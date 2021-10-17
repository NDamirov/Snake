#pragma once

#include "Field.h"
#include "Interface.h"
#include "Snake.h"

enum class State { IN_PROGRESS, LOSE };

const double delay = 0.3;

class Game {
public:
  Game(size_t field_w, size_t field_h);
  void Run();

private:
  Snake snake;
  Field field;
  Interface interface;
  State state;
  size_t score;

  void ParseKey();
  void MakeStep();
};
