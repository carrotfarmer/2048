#pragma once

typedef struct {
  int x;
  int y;
} Point;

Point findCenter(int x, int y, int width, int height);
int emptySlotCount(int arr[4][4]);
void fillEmptySlots(Point *slots, int arr[4][4]);
int genRandom(int range);
