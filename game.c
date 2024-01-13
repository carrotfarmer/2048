#include "game.h"
#include <stdio.h>

void down(int grid[4][4]) {
  for (int j = 0; j < 4; ++j) {
    for (int i = 0; i < 3; ++i) {
      // bottom cell is empty
      if (grid[i + 1][j] == 0) {
        int tmp = grid[i][j];
        grid[i][j] = 0;
        grid[i + 1][j] = tmp;
      }
      // bottom cell has a tile
      else {
        // Merge
        if (grid[i][j] == grid[i + 1][j]) {
          grid[i + 1][j] += grid[i][j];
          grid[i][j] = 0;
        }
      }
    }
  }
}

void up(int grid[4][4]) {
  for (int j = 0; j < 4; ++j) {
    for (int i = 3; i > 0; --i) {
      // upper cell is empty
      if (grid[i - 1][j] == 0) {
        int tmp = grid[i][j];
        grid[i][j] = 0;
        grid[i - 1][j] = tmp;
      }
      // upper cell has a tile
      else {
        // Merge
        if (grid[i][j] == grid[i - 1][j]) {
          grid[i - 1][j] += grid[i][j];
          grid[i][j] = 0;
        }
      }
    }
  }
}

void right(int grid[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      // cell to the right is empty
      if (grid[i][j + 1] == 0) {
        int tmp = grid[i][j];
        grid[i][j] = 0;
        grid[i][j + 1] = tmp;
      }
      // cell to the right has a tile
      else {
        // Merge
        if (grid[i][j] == grid[i][j + 1]) {
          grid[i][j + 1] += grid[i][j];
          grid[i][j] = 0;
        }
      }
    }
  }
}

void left(int grid[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 3; j > 0; --j) {
      // cell to the left is empty
      if (grid[i][j - 1] == 0) {
        int tmp = grid[i][j];
        grid[i][j] = 0;
        grid[i][j - 1] = tmp;
      }
      // cell to the left has a tile
      else {
        // Merge
        if (grid[i][j] == grid[i][j - 1]) {
          grid[i][j - 1] += grid[i][j];
          grid[i][j] = 0;
        }
      }
    }
  }
}
