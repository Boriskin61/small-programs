#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Dimensions of the Maze */
enum {
  kWidth = 11,
  kHeight = 7
};

/* Hard-coded maze */
char maze[kHeight][kWidth] = {
    {'+', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '#', '|'},
    {'|', ' ', '|', ' ', '-', '-', '+', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '+', '-', '-', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|'},
    {'+', '-', '-', '-', '-', '-', '+', '-', '-', '-', '+'},
};

/**
 * Draw the maze state in the screen!
 */
void draw(void) {
  int i, j;
  for (i = 0; i < kHeight; i++) {
    for (j = 0; j < kWidth; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

enum {
  kMaxNumPlayerMoves = 28
};

/**
 * The main function
 */
int main(int argc, char *argv[]) {
  int x, y;     /* Player position */
  int ox, oy;   /* Old player position */
  int i = 0;    /* Iteration number */
  int l = 0;    /* length of input string */
  static char actions[kMaxNumPlayerMoves] = { 0 };

  if (argc < 2) {
    draw();

    printf(
      "\n"
      "Maze dimensions: %dx%d\n"
      "Player position: %dx%d\n"
      "Iteration no. %d\n"
      "actions the player moves with a sequence of 'w', 's', 'a' and 'd'\n"
      "Try to reach the price(#)!\n",
      kWidth, kHeight, x, y, i
    );
  } else {
    l = strlen(argv[1]);
    memcpy(actions, argv[1], l < kMaxNumPlayerMoves ? l : kMaxNumPlayerMoves);
  }

  /* Initial position */
  x = 1;
  y = 1;
  maze[y][x] = 'X';

  /* Iterate and run 'actions'. */
  for (;i < kMaxNumPlayerMoves; ++i) {
    /* Save old player position */
    ox = x;
    oy = y;

    /* Move player position depending on the actual command */
    switch (actions[i]) {
      case 'w':
        y--;
        break;
      case 's':
        y++;
        break;
      case 'a':
        x--;
        break;
      case 'd':
        x++;
        break;
      case '\0':
        printf(
          "Not enouph actions to leave maze\n"
          "You lose!\n");
        draw();
        return EXIT_FAILURE;
      default:
        printf(
          "Wrong command <%c>, only w,s,a,d are accepted!)\n"
          "You lose!\n",
          actions[i]);
        draw(); 
        return EXIT_FAILURE;
    }

    /* If hit the price, You Win!! */
    if (maze[y][x] == '#') {
      printf(
        "You win!\n"
        "Your solution <%s>\n", 
        actions);

      draw();
      return EXIT_SUCCESS;
    } 
    else if (maze[y][x] != ' ' && !((y == 2 && maze[y][x] == '|' && x > 0 && x < kWidth))) {
      printf(
        "Player position: %dx%d\n"
        "Iteration no. %d. Action: %c. %s\n"
        "You lose!\n",
        x, y, i, actions[i], "Blocked!");
      draw();
      return EXIT_FAILURE;
    } 
    else {
      maze[y][x] = 'X';
      printf(
        "Player position: %dx%d\n"
        "Iteration no. %d. Action: %c. %s\n", 
        x, y, i, actions[i], "");
    }
  }

  return EXIT_FAILURE;
}
