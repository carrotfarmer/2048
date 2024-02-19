#include <stdlib.h>
#include <string.h>
#include <time.h>

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
  if (emptySlotCount(arr) == 0) {
    return;
  }

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

int genRandom(int range) {
  srand(time(NULL));
  return rand() % range;
}

void copyGrid(int original[4][4], int newArr[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      newArr[i][j] = original[i][j];
    }
  }
}

int compareGrid(int a[4][4], int b[4][4]) {
  int result = memcmp(a, b, 4 * 4 * sizeof(int));
  return result != 0 ? 1 : 0;
}

int numDigits(int n) {
  if (n < 10)
    return 1;
  if (n < 100)
    return 2;
  if (n < 1000)
    return 3;
  if (n < 10000)
    return 4;
  if (n < 100000)
    return 5;
  if (n < 1000000)
    return 6;
  return 7;
}
