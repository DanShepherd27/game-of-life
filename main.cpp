#include "gamefield.h"
#include "cell.h"
#include <iostream>
#include <string>

void PrintGame(GameField& game) {
    // system("clear");
    std::cout << std::string( 20, '\n' );
    std::cout << "Game board:\n";
    std::cout << game.ToString();  
    std::cout << "Rounds left:" << game.rounds - 1 << "\n";  
}

int main() {
    #pragma region init_game
    // GameField game(20);
    // GameField game(60, 20, 'a');
    // GameField game(30, 0.7f);
    GameField game(50, 50, 0.4f);
    
    // std::vector<std::vector<Cell>> my_cells;
    // for(int i = 0; i < 5; i++)
    // {
    //     std::vector<Cell> row;
    //     for(int i = 0; i < 5; i++)
    //     {
    //         row.push_back(Cell(0.9f));
    //     }
    //     my_cells.push_back(row);
    // }
    // GameField game(30, 10, 5, 5, my_cells);

    bool any_live_cells = true;
    #pragma endregion

    while (game.rounds != 0 && any_live_cells)
    {
        PrintGame(game);
        std::cin.ignore();
        any_live_cells = game.NextRound();
    }

    std::cout << "Simulation finished.";

}