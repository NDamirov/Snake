#include "Game.h"

#include <chrono>
#include <thread>

Game::Game(size_t field_w, size_t field_h)
    : snake(10, 10, field_w, field_h), field(field_w, field_h),
      interface(field_w, field_h), state(State::IN_PROGRESS), score(1) {
  interface.PrintPos(field.GetBonus().first, field.GetBonus().second, "o");
  interface.PrintPos(0, field.width, std::string("Score: " + std::to_string(score)).c_str());
}

void Game::Run() {
  while (state == State::IN_PROGRESS) {
    auto start_time = std::chrono::system_clock::now();
    while (std::chrono::duration<double>(std::chrono::system_clock::now() -
                                         start_time).count() < delay) {
      ParseKey();
    }
    MakeStep();
  }
  if (state == State::LOSE) {
    interface.Clear();
    std::string message = "You lost.\nScore: " + std::to_string(score);
    interface.Print(message);
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  }
}

void Game::ParseKey() {
  if (interface.WasPressed()) {
    int pressed = interface.WhatPressed();
    if (pressed == 65) {
      snake.ChangeDirection(DIR::UP);
    } else if (pressed == 66) {
      snake.ChangeDirection(DIR::DOWN);
    } else if (pressed == 67) {
      snake.ChangeDirection(DIR::RIGHT);
    } else if (pressed == 68) {
      snake.ChangeDirection(DIR::LEFT);
    }
  } else {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

void Game::MakeStep() {
  auto new_head = snake.MoveHead();
  if (new_head != field.GetBonus()) {
    auto old_tail = snake.MoveTail();
    field.SetUnused(old_tail.first, old_tail.second);
    interface.PrintPos(old_tail.first, old_tail.second, ".");
  } else {
    ++score;
    interface.PrintPos(0, field.width, std::string("Score: " + std::to_string(score)).c_str());
    field.NewBonus();
  }
  interface.PrintPos(field.GetBonus().first, field.GetBonus().second, "o");
  if (field.IsUsed(new_head.first, new_head.second)) {
    state = State::LOSE;
    return;
  }
  field.SetUsed(new_head.first, new_head.second);
  interface.PrintPos(new_head.first, new_head.second, "*");
}
