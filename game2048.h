// Header file for 2048 game.
#ifndef GAME2048_H
#define GAME2048_H

using namespace std;

class Game2048
{
 public:
  Game2048();
  // Constructor.
  friend ostream& operator <<(ostream outs, const Game2048& the_object);
  // Outputs the game square to the console.
  void move_tiles(char direction);
  // Equivalent to swiping left/down/right/up using 'asdw' character inputs.
  void spawn_new();
  // After the player makes a move, new value of 2 is generated randomly in an empty tile.
  bool completed;
  // A true indicates that game is won.
  int calculate_score();
  // Calculates the total score accumulated after winning/losing.
  void check_lostgame();
  // Checks if the game is lost.
 private:
  int square[4][4];
  // 2d array containing the tiles on the 4x4 square.
};
