#include <stdio.h>

#include "raylib.h"

#include "utils.h"

#define SCREEN_WIDTH 840
#define SCREEN_HEIGHT 650

const int BOX_WIDTH = SCREEN_WIDTH / 6;
const int BOX_HEIGHT = SCREEN_HEIGHT / 6;

void renderGrid(int grid[4][4]) {
  int currX = SCREEN_WIDTH / 6;
  int currY = SCREEN_HEIGHT / 6;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      char txt[32];
      DrawRectangleLines(currX, currY, BOX_WIDTH, BOX_HEIGHT, LIGHTGRAY);
      snprintf(txt, 32, "%d", grid[i][j]);
      Point textCoords = center(currX, currY, BOX_WIDTH, BOX_HEIGHT);
      DrawText(txt, textCoords.x - 5, textCoords.y - 10, 30, GRAY);
      currX += BOX_WIDTH;
    }

    // reset x pos
    currX = BOX_WIDTH;

    // next "line"
    currY += BOX_HEIGHT;
  }
}

int main(void) {
  int arr[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
  };

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "2048");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    renderGrid(arr);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
