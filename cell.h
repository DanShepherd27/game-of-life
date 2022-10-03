#pragma once
#ifndef Cell_H
#define Cell_H

class Cell{
    public:
        Cell();
        Cell(const bool alive);
        Cell(const float probability);
        bool alive;
};

#endif