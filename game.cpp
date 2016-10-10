// Game file for the 2048 game.
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "game2048.h"
using namespace std;

// Needs object of class Game2048 with the following member functions/attributes:
// 1. Constructor
// 2. Overloaded output stream operator <<()
//    This is to display the present board to the player.
// 3. Function move_tiles(char direction) to move the tiles in a given direction.
// 4. Function spawn_new() to randomly spawn a new value of 2 in an empty tile.
// 5. Public attribute .status to show if game is lost, won, or ongoing.
// 6. Function to calculate the total score accumulated.
// 7. Function to check if the game is lost or won or ongoing.
// 8. Private attribute .square, a 2d 4 rows 4 cols array with the values.

int main()
{
  cout << "Welcome to 2048!\n\n"
       << "Enter 'a' to move tiles left, 's' to move down, 'd' to move right, and 'w' to move up.\n"
       << "The game ends when you reach 2048 on any given tile.\n"
       << "Your score will be the total value of all tiles in the game.\n\n";
  Game2048 this_game, previous_game;
  char player_input;
  cout << "This is the initial state of the 2048 board:\n\n"
       << this_game;
  int turns = 1;
  while (!(this_game.status == 0))
    {
      cout << "2048 Game Turn " << turns << "\n\n";
      turns++;
      cout << this_game;
      cout << "Enter 'a' 's' 'd' 'w' for left, down, right, and up.\n";
      cin >> player_input;
      // If player_input does not match a/s/d/w, the game square will simply not change.
      this_game.move_tiles(player_input);
      this_game.check_game_status; // Even though it returns a value it also modifies object's status. Overkill!
      if (this_game == previous_game)
	{
	  // Then player has done an illegal move and the game square was not changed.
	  // Do not spawn new tiles.
	}
      else
	{
	  // Player has made a legal move.
	  this_game.spawn_new();
	  // Record a snapshot of this game after the spawning. We need it as a point of
	  // comparison to figure out if the player made a legal move that changed the square.
	  previous_game = this_game;
	}
    }
  cout << "You scored: " << this_game.calculate_score() << "\n";
  cout << "Enter anything to exit: ";
  cin >> player_input;
  return 0;
}
