#pragma once

#include <string>

class Interface {
public:
  Interface(size_t field_w, size_t field_h);

  bool WasPressed();
  int WhatPressed();

  void Print(std::string str);
  void PrintPos(size_t h, size_t w, const char *str);

  void Clear();

  ~Interface();

private:
};
