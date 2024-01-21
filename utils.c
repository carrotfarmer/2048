#include <stdlib.h>
#include <string.h>

#include "utils.h"

Point findCenter(int x, int y, int width, int height) {
  Point center = {.x = x + (width / 2), .y = y + (height / 2)};
  return center;
}

int emptySlotCount(int arr[4][4]) {
  int count = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (arr[i][j] == 0) {
        count++;
      }
    }
  }

  return count;
}

void fillEmptySlots(Point slots[], int arr[4][4]) {
  int slotIndex = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (arr[i][j] == 0) {
        Point p = {.y = i, .x = j};
        slots[slotIndex] = p;
        slotIndex++;
      }
    }
  }
};

int genRandom(int range) { return rand() % range; }

void copyGrid(int original[4][4], int new[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      new[i][j] = original[i][j];
    }
  }
}

int compareGrid(int a[4][4], int b[4][4]) {
  int e;
  // NOTE: deref a, since sizeof(a) returns size of pointer :skull:
  e = memcmp(a, b, sizeof(*a));

  return e;
}
