#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEFAULT_STACK_SIZE      1000
#define DEFAULT_CALL_STACK_SIZE 100
#define DEFAULT_NUM_LOCALS      10

typedef enum {
    NOOP    = 0x60,
    IADD    = 0x61,   // int add
    ISUB    = 0x62,
    IMUL    = 0x63,
    ILT     = 0x64,   // int less than
    IEQ     = 0x65,   // int equal
    BR      = 0x66,   // branch
    BRT     = 0x67,   // branch if true
    BRF     = 0x68,   // branch if true
    ICONST  = 0x69,   // push constant integer
    LOAD    = 0x6a,  // load from local context
    GLOAD   = 0x6b,  // load from global memory
    STORE   = 0x6c,  // store in local context
    GSTORE  = 0x6d,  // store in global memory
    PRINT   = 0x6e,  // print stack top
    POP     = 0x6f,  // throw away top of stack
    CALL    = 0x70,  // call function at address with nargs,nlocals
    RET     = 0x71,  // return value from function
    HALT    = 0x72
} VM_CODE;

typedef struct {
    int returnip;
    int locals[DEFAULT_NUM_LOCALS];
} Context;

typedef struct {
    int *code;
    int code_size;

    // global variable space
    int *globals;
    int nglobals;

    // Operand stack, grows upwards
    int stack[DEFAULT_STACK_SIZE];
    Context call_stack[DEFAULT_CALL_STACK_SIZE];
} VM;

typedef struct {
    char name[8];
    int nargs;
} VM_INSTRUCTION;

static VM_INSTRUCTION vm_instructions[] = {
    { "noop",   0 },    // 0
    { "iadd",   0 },    // 1
    { "isub",   0 },    // 2
    { "imul",   0 },    // 3
    { "ilt",    0 },    // 4
    { "ieq",    0 },    // 5
    { "br",     1 },    // 7
    { "brt",    1 },    // 8
    { "brf",    1 },    // 9
    { "iconst", 1 },    // 10
    { "load",   1 },
    { "gload",  1 },
    { "store",  1 },
    { "gstore", 1 },
    { "print",  0 },
    { "pop",    0 },
    { "call",   3 },
    { "ret",    0 },
    { "halt",   0 }
};

VM *vm_create(int *code, int code_size, int nglobals);
void vm_free(VM *vm);
void vm_init(VM *vm, int *code, int code_size, int nglobals);
void vm_exec(VM *vm, int startip, bool trace);
void vm_print_instr(int *code, int ip);
void vm_print_stack(int *stack, int count);
void vm_print_data(int *globals, int count);

static void vm_context_init(Context *ctx, int ip, int nlocals) {
    if ( nlocals>DEFAULT_NUM_LOCALS ) {
        fprintf(stderr, "too many locals requested: %d\n", nlocals);
    }
    ctx->returnip = ip;
}

void vm_init(VM *vm, int *code, int code_size, int nglobals)
{
    vm->code = code;
    vm->code_size = code_size;
    vm->globals = calloc(nglobals, sizeof(int));
    vm->nglobals = nglobals;
}

void vm_free(VM *vm)
{
    free(vm->globals);
    free(vm);
}

VM *vm_create(int *code, int code_size, int nglobals)
{
    VM *vm = calloc(1, sizeof(VM));
    vm_init(vm, code, code_size, nglobals);
    return vm;
}

void vm_exec(VM *vm, int startip, bool trace)
{
    // registers
    int ip;         // instruction pointer register
    int sp;         // stack pointer register
    int callsp;     // call stack pointer register

    int a = 0;
    int b = 0;
    int addr = 0;
    int offset = 0;

    ip = startip;
    sp = -1;
    callsp = -1;
    int opcode = vm->code[ip];

    while (opcode != HALT && ip < vm->code_size) {
        if (trace) vm_print_instr(vm->code, ip);
        ip++; //jump to next instruction or to operand
        switch (opcode) {
            case IADD:
                b = vm->stack[sp--];           // 2nd opnd at top of stack
                a = vm->stack[sp--];           // 1st opnd 1 below top
                vm->stack[++sp] = a + b;       // push result
                break;
            case ISUB:
                b = vm->stack[sp--];
                a = vm->stack[sp--];
                vm->stack[++sp] = a - b;
                break;
            case IMUL:
                b = vm->stack[sp--];
                a = vm->stack[sp--];
                vm->stack[++sp] = a * b;
                break;
            case ILT:
                b = vm->stack[sp--];
                a = vm->stack[sp--];
                vm->stack[++sp] = (a < b) ? true : false;
                break;
            case IEQ:
                b = vm->stack[sp--];
                a = vm->stack[sp--];
                vm->stack[++sp] = (a == b) ? true : false;
                break;
            case BR:
                ip = vm->code[ip];
                break;
            case BRT:
                addr = vm->code[ip++];
                if (vm->stack[sp--] == true) ip = addr;
                break;
            case BRF:
                addr = vm->code[ip++];
                if (vm->stack[sp--] == false) ip = addr;
                break;
            case ICONST:
                vm->stack[++sp] = vm->code[ip++];  // push operand
                break;
            case LOAD: // load local or arg
                offset = vm->code[ip++];
                vm->stack[++sp] = vm->call_stack[callsp].locals[offset];
                break;
            case GLOAD: // load from global memory
                addr = vm->code[ip++];
                vm->stack[++sp] = vm->globals[addr];
                break;
            case STORE:
                offset = vm->code[ip++];
                vm->call_stack[callsp].locals[offset] = vm->stack[sp--];
                break;
            case GSTORE:
                addr = vm->code[ip++];
                vm->globals[addr] = vm->stack[sp--];
                break;
            case PRINT:
                printf("%d\n", vm->stack[sp--]);
                break;
            case POP:
                --sp;
                break;
            case CALL:
                // expects all args on stack
                addr = vm->code[ip++];			// index of target function
                int nargs = vm->code[ip++]; 	// how many args got pushed
                int nlocals = vm->code[ip++]; 	// how many locals to allocate
                ++callsp; // bump stack pointer to reveal space for this call
                vm_context_init(&vm->call_stack[callsp], ip, nargs+nlocals);
                // copy args into new context
                for (int i=0; i<nargs; i++) {
                    vm->call_stack[callsp].locals[i] = vm->stack[sp-i];
                }
                sp -= nargs;
                ip = addr;		// jump to function
                break;
            case RET:
                ip = vm->call_stack[callsp].returnip;
                callsp--; // pop context
                break;
            default:
                printf("invalid opcode: %d at ip=%d\n", opcode, (ip - 1));
                exit(1);
        }
        if (trace) vm_print_stack(vm->stack, sp);
        opcode = vm->code[ip];
    }
    if (trace) vm_print_data(vm->globals, vm->nglobals);
}

void vm_print_instr(int *code, int ip)
{
    int opcode = code[ip];
    VM_INSTRUCTION *inst = &vm_instructions[opcode];
    switch (inst->nargs) {
        case 0:
            printf("%04d:  %-20s", ip, inst->name);
            break;
        case 1:
            printf("%04d:  %-10s%-10d", ip, inst->name, code[ip + 1]);
            break;
        case 2:
            printf("%04d:  %-10s%d,%10d", ip, inst->name, code[ip + 1], code[ip + 2]);
            break;
        case 3:
            printf("%04d:  %-10s%d,%d,%-6d", ip, inst->name, code[ip + 1], code[ip + 2], code[ip + 3]);
            break;
    }
}

void vm_print_stack(int *stack, int count)
{
    printf("stack=[");
    for (int i = 0; i <= count; i++) {
        printf(" %d", stack[i]);
    }
    printf(" ]\n");
}

void vm_print_data(int *globals, int count)
{
    printf("Data memory:\n");
    for (int i = 0; i < count; i++) {
        printf("%04d: %d\n", i, globals[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    char *bytecode = argv[1];
    int length = strlen(bytecode);

    int *code = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; ++i) {
        code[i] = bytecode[i];
    }

    VM *vm = vm_create(code, length, 0);
	vm_exec(vm, 0, false);
	vm_free(vm);

    return 0;
}