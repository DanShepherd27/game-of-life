#pragma once
#ifndef GameField_H
#define GameField_H

#include "cell.h"
#include <iostream>
#include <vector> 
#include <string>

class GameField{
    public: 
    // Constructors
        GameField(unsigned const int size);
        GameField(unsigned const int width, unsigned const int height, char dummy);
        GameField(unsigned const int size, const float probability) ;
        GameField(unsigned const int width, unsigned const int height, const float probability) ;
        GameField(unsigned const int width, unsigned const int height, unsigned const int top, unsigned const int left, std::vector<std::vector<Cell> > provided_cells);
    // Fields
        unsigned int width;    
        unsigned int height;
        std::vector<std::vector<Cell> > cells;
        unsigned int rounds;
    // Methods
        void InitializeCells(const float probability) ;
        void InitializeCells(unsigned const int top, unsigned const int left, std::vector<std::vector<Cell> > provided_cells);
        bool NextRound();
        bool AnyCellsAlive();
        const unsigned int CountNeighbours(const unsigned int i, const unsigned int j);
        std::string ToString();
};

#endif