#include "cell.h"
#include <iostream>
#include <random>

Cell::Cell() {
    alive = false;
}

Cell::Cell(const bool alive) {
    this->alive = alive;
}

Cell::Cell(const float probability) {
    std::random_device rD;
    std::default_random_engine rE(rD());
    std::uniform_int_distribution<int> uniform_dist(1, 100);
    alive = uniform_dist(rE) <= probability*100;
}
