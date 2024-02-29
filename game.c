#include <stdbool.h>

#include "game.h"
#include "utils.h"

void down(int grid[4][4], int *score, int shouldScoreUpdate) {
  int prevGrid[4][4];
  copyGrid(grid, prevGrid);

  for (int col = 0; col < 4; ++col) {
    int curr = 3;
    for (int row = 3; row >= 0; --row) {
      if (grid[row][col] != 0) {
        grid[curr][col] = grid[row][col];
        if (curr != row) {
          grid[row][col] = 0;
        }
        --curr;
      }
    }
  }

  for (int col = 0; col < 4; ++col) {
    for (int row = 3; row > 0; --row) {
      if (grid[row][col] == grid[row - 1][col]) {
        grid[row][col] *= 2;
        if (shouldScoreUpdate)
          *score += grid[row][col];
        grid[row - 1][col] = 0;
      }
    }
  }

  // sort
  for (int col = 0; col < 4; ++col) {
    int curr = 3;
    for (int row = 3; row >= 0; --row) {
      if (grid[row][col] != 0) {
        grid[curr][col] = grid[row][col];
        if (curr != row)
          grid[row][col] = 0;
        --curr;
      }
    }
  }

  if (compareGrid(prevGrid, grid) == 1) {
    genTile(grid);
  }
}

void up(int grid[4][4], int *score, int shouldScoreUpdate) {
  int prevGrid[4][4];
  copyGrid(grid, prevGrid);

  for (int col = 0; col < 4; ++col) {
    int curr = 0;
    for (int row = 0; row < 4; ++row) {
      if (grid[row][col] != 0) {
        grid[curr][col] = grid[row][col];
        if (curr != row) {
          grid[row][col] = 0;
        }
        ++curr;
      }
    }
  }

  for (int col = 0; col < 4; ++col) {
    for (int row = 0; row < 3; ++row) {
      if (grid[row][col] == grid[row + 1][col]) {
        grid[row][col] *= 2;
        if (shouldScoreUpdate)
          *score += grid[row][col];
        grid[row + 1][col] = 0;
      }
    }
  }

  // sort
  for (int col = 0; col < 4; ++col) {
    int curr = 0;
    for (int row = 0; row < 4; ++row) {
      if (grid[row][col] != 0) {
        grid[curr][col] = grid[row][col];
        if (curr != row)
          grid[row][col] = 0;
        ++curr;
      }
    }
  }

  if (compareGrid(prevGrid, grid) == 1) {
    genTile(grid);
  }
};

void right(int grid[4][4], int *score, int shouldScoreUpdate) {
  int prevGrid[4][4];
  copyGrid(grid, prevGrid);

  for (int row = 0; row < 4; ++row) {
    int curr = 3;
    for (int col = 3; col >= 0; --col) {
      if (grid[row][col] != 0) {
        grid[row][curr] = grid[row][col];
        if (curr != col) {
          grid[row][col] = 0;
        }
        --curr;
      }
    }
  }

  for (int row = 0; row < 4; ++row) {
    for (int col = 3; col > 0; --col) {
      if (grid[row][col] == grid[row][col - 1]) {
        grid[row][col] *= 2;
        if (shouldScoreUpdate)
          *score += grid[row][col];
        grid[row][col - 1] = 0;
      }
    }
  }

  // sort
  for (int row = 0; row < 4; ++row) {
    int curr = 3;
    for (int col = 3; col >= 0; --col) {
      if (grid[row][col] != 0) {
        grid[row][curr] = grid[row][col];
        if (curr != col)
          grid[row][col] = 0;
        --curr;
      }
    }
  }

  if (compareGrid(prevGrid, grid) == 1 && emptySlotCount(grid) > 0) {
    genTile(grid);
  }
}

void left(int grid[4][4], int *score, int shouldScoreUpdate) {
  int prevGrid[4][4];
  copyGrid(grid, prevGrid);

  for (int row = 0; row < 4; ++row) {
    int curr = 0;
    for (int col = 0; col < 4; ++col) {
      if (grid[row][col] != 0) {
        grid[row][curr] = grid[row][col];
        if (curr != col) {
          grid[row][col] = 0;
        }
        ++curr;
      }
    }
  }

  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 3; ++col) {
      if (grid[row][col] == grid[row][col + 1]) {
        grid[row][col] *= 2;
        if (shouldScoreUpdate)
          *score += grid[row][col];
        grid[row][col + 1] = 0;
      }
    }
  }

  // sort
  for (int row = 0; row < 4; ++row) {
    int curr = 0;
    for (int col = 0; col < 4; ++col) {
      if (grid[row][col] != 0) {
        grid[row][curr] = grid[row][col];
        if (curr != col)
          grid[row][col] = 0;
        ++curr;
      }
    }
  }

  if (compareGrid(prevGrid, grid) == 1 && emptySlotCount(grid) > 0) {
    genTile(grid);
  }
};

bool isGameOver(int grid[4][4], int *score) {
  if (emptySlotCount(grid) > 0) {
    return false;
  }

  int newGrid[4][4];
  copyGrid(grid, newGrid);

  down(newGrid, score, 0);
  up(newGrid, score, 0);
  right(newGrid, score, 0);
  left(newGrid, score, 0);

  return compareGrid(grid, newGrid) == 0 ? true : false;
}

void genTile(int grid[4][4]) {
  int emptySlots = emptySlotCount(grid);
  if (emptySlots == 0) {
    return;
  }
  Point emptySlotsArr[emptySlots];
  fillEmptySlots(emptySlotsArr, grid);

  Point newPoint =
      emptySlotsArr[genRandom(sizeof(emptySlotsArr) / sizeof(Point))];
  grid[newPoint.y][newPoint.x] = 2;
}
