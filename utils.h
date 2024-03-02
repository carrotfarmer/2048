#pragma once

typedef struct {
  int x;
  int y;
} Point;

Point findCenter(int x, int y, int width, int height);
int emptySlotCount(int arr[4][4]);
void fillEmptySlots(Point *slots, int arr[4][4]);
int genRandom(int range);
void copyGrid(int original[4][4], int newArr[4][4]);
int compareGrid(int a[4][4], int b[4][4]);
int numDigits(int n);

void saveEncryptedScore(int score);
int decryptHighScore();
