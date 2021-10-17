#include "Field.h"

#include <ctime>

Field::Field(size_t width, size_t height) : width(width), height(height), rnd(time(nullptr)) {
    field_.resize(height, std::vector<bool>(width, false));
    NewBonus();
}

bool Field::IsUsed(size_t y, size_t x) {
    return field_[y][x];
}

void Field::SetUsed(size_t y, size_t x) {
    field_[y][x] = true;
}

void Field::SetUnused(size_t y, size_t x) {
    field_[y][x] = false;
}

void Field::NewBonus() {
    bonus.first = rnd() % height;
    bonus.second = rnd() % width;
}

std::pair<size_t, size_t> Field::GetBonus() {
    return bonus;
}
