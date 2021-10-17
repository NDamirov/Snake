#pragma once

#include <queue>

enum class DIR { UP, RIGHT, DOWN, LEFT };

class Snake {
public:
  Snake(size_t x, size_t y, size_t w, size_t h);

  void ChangeDirection(DIR new_dir);
  std::pair<size_t, size_t> MoveHead();
  std::pair<size_t, size_t> MoveTail();

private:
  size_t head_x;
  size_t head_y;
  DIR dir;

  size_t field_w;
  size_t field_h;

  std::queue<std::pair<size_t, size_t>> body;
};
