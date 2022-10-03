#include "gamefield.h"
#include "cell.h"
#include <iostream>
#include <vector> 
#include <string>


GameField::GameField(unsigned const int size) { 
    width = size;
    height = size;
    rounds = 100;
    InitializeCells(0.1f);
}

GameField::GameField(unsigned const int width, unsigned const int height, char dummy) { 
    this->width = width;
    this->height = height; 
    rounds = 100;
    InitializeCells(0.1f);
}

GameField::GameField(unsigned const int size, const float probability) { 
    this->width = size;
    this->height = size;
    rounds = 100;
    InitializeCells(probability);
}

GameField::GameField(unsigned const int width, unsigned const int height, const float probability) { 
    this->width = width;
    this->height = height; 
    rounds = 100;
    InitializeCells(probability);
}

GameField::GameField(unsigned const int width, unsigned const int height, unsigned const int top, unsigned const int left, std::vector<std::vector<Cell>> provided_cells) { 
    this->width = width;
    this->height = height; 
    rounds = 100;
    InitializeCells(top, left, provided_cells);
}

// Methods
void GameField::InitializeCells(const float probability) {
    cells.resize(height);
    for (auto &x: cells)
    {
        x.resize(width);
        for (auto &y: x)
        {
            y = Cell(probability);
        }
        
    }
}    

void GameField::InitializeCells(unsigned const int top, unsigned const int left, std::vector<std::vector<Cell>> provided_cells) {

    cells.resize(height);
    for (int i = 0; i < height; i++)
    {
        cells[i].resize(width);
        for (int j = 0; j < width; j++)
        {
            if(i >= top && j >= left && i - (int)top < provided_cells.size() && j - (int)left < provided_cells[i - (int)top].size())
               cells[i][j] = provided_cells[i - top][j - left];
            else
                cells[i][j] = Cell(false);
        }   
    }
}

bool GameField::NextRound() {
    if(rounds-- != 0 && AnyCellsAlive()) {
        std::vector<std::vector<Cell> > next_cells = cells;
    
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                const unsigned int num_of_neighbours = CountNeighbours(i, j);

                // Rule 1
                // Nothing happens

                //Rule 2
                if(num_of_neighbours < 2 || num_of_neighbours > 3)
                    next_cells[i][j].alive = false;

                // Rule 3
                if(num_of_neighbours == 3)
                    next_cells[i][j].alive = true;
            }   
        }
        cells = next_cells;
        return true;
    }
    return false;               
}

bool GameField::AnyCellsAlive(){
    for (auto &x: cells)
    {
        for (auto &y: x)
        {
            if(y.alive){
                return true;
            }
        }
            
    }
    return false;
}

const unsigned int GameField::CountNeighbours(const unsigned int i, const unsigned int j){
    unsigned int num_of_neighbours = 0;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if(!(x == 1 && y == 1) && (int)i - 1 + x >= 0 && (int)j - 1 + y >= 0 && (int)i - 1 + x < height && (int)j - 1 + y < width && cells[i-1+x][j-1+y].alive)
                num_of_neighbours++;
        }
    }
    return num_of_neighbours;
}

std::string GameField::ToString() {
    std::string s = "";
    for (auto &row: cells)
    {
        for (auto &cell: row)
        {
            if(cell.alive)
                s.append("X");
            else    
                s.append("_");
        }
        s.append("\n");                    
    }
    return s;
}