#include "utils.h"

Point center(int x, int y, int width, int height) {
  Point center;
  center.x = x + (width / 2);
  center.y = y + (height / 2);
  return center;
}
