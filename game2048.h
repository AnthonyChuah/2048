// Header file for 2048 game.
#ifndef GAME2048_H
#define GAME2048_H

using namespace std;

class Game2048
{
public:
  Game2048();
  // Constructor.
  Game2048(const Game2048& copyee_object);
  // Copy constructor.
  friend ostream& operator <<(ostream& outs, const Game2048& the_object);
  // Outputs the game square to the console.
  friend bool operator ==(const Game2048& left_object, const Game2048& right_object);
  // Overloaded comparison equality operator to see if two games have the same squares.
  void move_tiles(char direction);
  // Equivalent to swiping left/down/right/up using 'asdw' character inputs.
  void spawn_new();
  // After the player makes a move, new value of 2 is generated randomly in an empty tile.
  int status;
  // 0 means game is ongoing, 1 means it is lost, 2 means it is won.
  int calculate_score();
  // Calculates the total score accumulated after winning/losing.
  int check_game_status();
  // Checks if the game is over: returns 0 for ongoing, 1 for lost, and 2 for won.
private:
  // Private methods to check if it is possible to swipe left/right/up/down.
  bool left_possible();
  bool right_possible();
  bool up_possible();
  bool down_possible();
  // move_direction follows the standard rules for 2048 tile movement:
  // Move up to fill the blank spaces, join up same values, then move up again to fill blanks.
  // More description in implementation of Game2048::move_left().
  void move_left();
  void move_right();
  void move_down();
  void move_up();
  int square[4][4];
  // 2d array containing the tiles on the 4x4 square.
};

#endif
