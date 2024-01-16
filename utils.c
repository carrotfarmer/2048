#include <stdlib.h>

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
