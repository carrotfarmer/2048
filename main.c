#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "raylib.h"

#include "game.h"
#include "utils.h"

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700

#define BORDER_WIDTH 12

#define MAX_FONT_SIZE 300
#define MAX_FONT_CHARS 250

// font sizes
#define SINGLE_DIGIT 65
#define DOUBLE_DIGIT 60
#define TRIPLE_DIGIT 50
#define QUAD_DIGIT 45

const int BOX_WIDTH = (SCREEN_WIDTH / 6) - BORDER_WIDTH;
const int BOX_HEIGHT = (SCREEN_HEIGHT / 6) - BORDER_WIDTH;

const Color BORDER_COLOR = {187, 173, 160, 255};

// tiles < 8
const Color SMALL_TEXT_COLOR = {119, 110, 101, 1};

// tiles >= 8
const Color BIG_TEXT_COLOR = {249, 246, 242, 1};

void drawTile(int x, int y, Color color) {
  // it is what it is 💀
  if (y == BOX_HEIGHT + BORDER_WIDTH) {
    DrawRectangle(x, y, BOX_WIDTH - BORDER_WIDTH, BOX_HEIGHT - BORDER_WIDTH,
                  color);
  } else {
    DrawRectangle(x + BORDER_WIDTH, y, BOX_WIDTH - BORDER_WIDTH,
                  BOX_HEIGHT - BORDER_WIDTH, color);
  }
}

Color getTileColor(int tileVal) {
  // get tile color based on tile value
  switch (tileVal) {
  case 0:
    return (Color){205, 193, 180, 255};
    break;
  case 2:
    return (Color){238, 228, 218, 255};
    break;
  case 4:
    return (Color){237, 224, 200, 255};
    break;
  case 8:
    return (Color){242, 177, 121, 255};
    break;
  case 16:
    return (Color){245, 149, 99, 255};
    break;
  case 32:
    return (Color){246, 124, 95, 255};
    break;
  case 64:
    return (Color){246, 94, 59, 255};
    break;
  case 128:
    return (Color){237, 207, 114, 255};
    break;
  case 256:
    return (Color){237, 204, 97, 255};
    break;
  case 512:
    return (Color){237, 200, 80, 255};
    break;
  case 1024:
    return (Color){237, 197, 63, 255};
    break;
  case 2048:
    return (Color){237, 194, 46, 255};
    break;
  case 4096:
    return (Color){237, 194, 46, 255};
    break;
  case 8192:
    return (Color){237, 194, 46, 255};
    break;
  default:
    return (Color){237, 194, 46, 255};
    break;
  }
}

void drawText(int tileVal, int currX, int currY, Font font) {
  char txt[32];
  snprintf(txt, 32, "%d", tileVal);

  Point textCoords = findCenter(currX, currY, BOX_WIDTH, BOX_HEIGHT);

  if (currY == BOX_HEIGHT + BORDER_WIDTH) {
    textCoords.x -= 15;
  }

  if (strcmp(txt, "0")) {
    if (tileVal > 1000) {
      DrawTextEx(font, txt, (Vector2){textCoords.x - 34, textCoords.y - 26},
                 QUAD_DIGIT, 0, WHITE);
    } else if (tileVal > 100) {
      DrawTextEx(font, txt, (Vector2){textCoords.x - 25, textCoords.y - 28},
                 TRIPLE_DIGIT, 0, WHITE);
    } else if (tileVal > 10) {
      DrawTextEx(font, txt, (Vector2){textCoords.x - 16, textCoords.y - 35},
                 DOUBLE_DIGIT, 0, WHITE);
    } else {
      DrawTextEx(font, txt, (Vector2){textCoords.x - 8, textCoords.y - 35},
                 SINGLE_DIGIT, 0, GRAY);
    }
  }
}

void renderGrid(int grid[4][4], Font font) {
  // Grid Lines
  // horizontal
  for (int i = 0; i < 5; ++i) {
    DrawRectangle(BOX_WIDTH, BOX_WIDTH + (i * BOX_WIDTH),
                  (BOX_WIDTH * 4) + BORDER_WIDTH, BORDER_WIDTH, BORDER_COLOR);
  }

  // vertical
  for (int i = 0; i < 5; ++i) {
    DrawRectangle(BOX_WIDTH + (i * BOX_WIDTH), BOX_WIDTH, BORDER_WIDTH,
                  BOX_WIDTH * 4, BORDER_COLOR);
  }

  int currX = SCREEN_WIDTH / 6;
  int currY = SCREEN_HEIGHT / 6;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      drawTile(currX, currY, getTileColor(grid[i][j]));
      drawText(grid[i][j], currX, currY, font);
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
      {16, 32, 64, 128},
      {4, 4, 4, 4},
      {8, 8, 8, 8},
      {128, 256, 512, 1024},
  };

  int tileSpotX = genRandom(4);
  int tileSpotY = genRandom(4);

  arr[tileSpotX][tileSpotY] = 2;

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "2048");

  SetTargetFPS(60);

  Font openSans = LoadFontEx("fonts/OpenSans-ExtraBold.ttf", MAX_FONT_SIZE, 0,
                             MAX_FONT_CHARS);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_DOWN)) {
      if (!isGameOver(arr))
        down(arr);
    }
    if (IsKeyPressed(KEY_UP)) {
      if (!isGameOver(arr))
        up(arr);
    }
    if (IsKeyPressed(KEY_RIGHT)) {
      if (!isGameOver(arr))
        right(arr);
    }
    if (IsKeyPressed(KEY_LEFT)) {
      if (!isGameOver(arr)) {
        left(arr);
      } else {
        printf("game over");
      }
    }

    ClearBackground((Color){250, 248, 239, 1});

    renderGrid(arr, openSans);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
