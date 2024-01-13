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
