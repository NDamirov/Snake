#pragma once

#include <vector>
#include <random>

class Field {
public:
    size_t width;
    size_t height;

    Field(size_t width, size_t height);

    bool IsUsed(size_t y, size_t x);
    void SetUsed(size_t y, size_t x);
    void SetUnused(size_t y, size_t x);

    void NewBonus();
    std::pair<size_t, size_t> GetBonus();

private:
    std::vector<std::vector<bool>> field_;
    std::pair<size_t, size_t> bonus;
    std::mt19937 rnd;
};

