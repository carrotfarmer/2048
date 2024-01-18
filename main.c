#include <stdio.h>
#include <string.h>

#include "raylib.h"

#include "game.h"
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
      Point textCoords = findCenter(currX, currY, BOX_WIDTH, BOX_HEIGHT);
      if (strcmp(txt, "0")) {
        if (grid[i][j] > 1000) {
          DrawText(txt, textCoords.x - 60, textCoords.y - 20, 60, GRAY);
        } else if (grid[i][j] > 100) {
          DrawText(txt, textCoords.x - 40, textCoords.y - 20, 60, GRAY);
        } else {
          DrawText(txt, textCoords.x - 10, textCoords.y - 20, 60, GRAY);
        }
      }
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
      {0, 0, 4, 0},
      {0, 0, 1024, 4},
      {0, 0, 4, 0},
      {0, 0, 4, 0},
  };

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "2048");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_DOWN))
      down(arr);
    if (IsKeyPressed(KEY_UP))
      up(arr);
    if (IsKeyPressed(KEY_LEFT))
      left(arr);
    if (IsKeyPressed(KEY_RIGHT))
      right(arr);

    BeginDrawing();

    ClearBackground(RAYWHITE);

    renderGrid(arr);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
