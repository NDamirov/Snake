#include "Snake.h"

Snake::Snake(size_t x, size_t y, size_t w, size_t h)
    : head_x(x), head_y(y), field_w(w), field_h(h) {
  body.push({x, y});
}

void Snake::ChangeDirection(DIR new_dir) { dir = new_dir; }

std::pair<size_t, size_t> Snake::MoveHead() {
  std::pair<size_t, size_t> new_head = body.back();
  if (dir == DIR::UP) {
    if (new_head.first == 0) {
      new_head.first = field_h - 1;
    } else {
      --new_head.first;
    }
  } else if (dir == DIR::LEFT) {
    if (new_head.second == 0) {
      new_head.second = field_w - 1;
    } else {
      --new_head.second;
    }
  } else if (dir == DIR::DOWN) {
    ++new_head.first;
    if (new_head.first == field_h) {
      new_head.first = 0;
    }
  } else {
    ++new_head.second;
    if (new_head.second == field_w) {
      new_head.second = 0;
    }
  }
  body.push(new_head);
  return new_head;
}

std::pair<size_t, size_t> Snake::MoveTail() {
  auto tail = body.front();
  body.pop();
  return tail;
}
