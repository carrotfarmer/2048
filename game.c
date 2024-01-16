#include "game.h"
#include "utils.h"

void down(int grid[4][4]) {
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

  for (int col = 0; col < 4; ++col) {
    for (int row = 3; row > 0; --row) {
      if (grid[row][col] == grid[row - 1][col]) {
        grid[row][col] *= 2;
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

  genTile(grid);
}

void up(int grid[4][4]) {
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

  for (int col = 0; col < 4; ++col) {
    for (int row = 0; row < 3; ++row) {
      if (grid[row][col] == grid[row + 1][col]) {
        grid[row][col] *= 2;
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

  genTile(grid);
};

void right(int grid[4][4]) {
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

  for (int row = 0; row < 4; ++row) {
    for (int col = 3; col > 0; --col) {
      if (grid[row][col] == grid[row][col - 1]) {
        grid[row][col] *= 2;
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

  genTile(grid);
}

void left(int grid[4][4]) {
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

  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 3; ++col) {
      if (grid[row][col] == grid[row][col + 1]) {
        grid[row][col] *= 2;
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

  genTile(grid);
};

void genTile(int grid[4][4]) {
  int emptySlots = emptySlotCount(grid);
  Point emptySlotsArr[emptySlots];
  fillEmptySlots(emptySlotsArr, grid);
  Point newPoint = emptySlotsArr[genRandom(4)];
  grid[newPoint.y][newPoint.x] = 2;
}
