// Game file for the 2048 game.
#include <iostream>
#include <cmath>
#include <algorithm>
#include "game2048.h"
using namespace std;

// Needs object of class Game2048 with the following member functions/attributes:
// 1. Constructor
// 2. Overloaded output stream operator <<()
//    This is to display the present board to the player.
// 3. Function move_tiles(char direction) to move the tiles in a given direction.
// 4. Function spawn_new() to randomly spawn a new value of 2 in an empty tile.
// 5. Public attribute .completed to show if the game is won.
// 6. Function to calculate the total score accumulated.
// 7. Function to check if the game is lost.
// 8. Private attribute .square, a 2d 4 rows 4 cols array with the values.

int main()
{
  cout << "Welcome to 2048!\n\n"
       << "Enter 'a' to move tiles left, 's' to move down, 'd' to move right, and 'w' to move up.\n"
       << "The game ends when you reach 2048 on any given tile.\n"
       << "Your score will be the total value of all tiles in the game.\n\n";
  Game2048 this_game;
  cout << "This is the initial state of the 2048 board:\n\n"
       << this_game;
  int turns = 1;
  while (!(this_game.completed))
    {
      cout << "2048 Game Turn " << turns << "\n\n";
      
    }
}
