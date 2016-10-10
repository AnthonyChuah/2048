// Implementation file for 2048 game corresponding to header file game2048.h.
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <windows.h>
#include "game2048.h"
using namespace std;

Game2048::Game2048()
{
  // First fill everything in square with 0.
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      square[i][j] = 0;
  // Generate a 2 in a random tile.
  int rand_row, rand_col;
  rand_row = rand() % 4;
  rand_col = rand() % 4;
  square[rand_row][rand_col] = 2;
  // Set game status to 0 which means ongoing game.
  status = 0;
}

Game2048::Game2048(const Game2048& copyee_object)
{
  status = copyee_object.status;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      {
	square[i][j] = copyee_object.square[i][j];
      }
}

ostream& operator <<(ostream& outs, const Game2048& the_object)
{
  outs << "+-------------------+\n";
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      {
	outs << "|" << setw(4) << square[i][j];
	if (j == 3)
	  {
	    outs << "|\n";
	    outs << "|-------------------|\n";
	  }
      }
  outs << "+-------------------+\n";
  return outs;
}

bool operator ==(const Game2048& left_object, const Game2048& right_object)
{
  int count_equalities = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      {
	if (left_object.square[i][j] == right_object.square[i][j])
	  count_equalities++;
      }
  if (count_equalities == 16)
    return true;
  else
    return false;
}

void Game2048::move_tiles(char direction);
{
  // If 'a' left swipe: first check if it is a possible move.
  if (direction == 'a' && left_possible())
    move_left();
  if (direction == 'd' && right_possible())
    move_right();
  if (direction == 's' && down_possible())
    move_down();
  if (direction == 'w' && up_possible())
    move_up();
}

void Game2048::move_left()
{
  // A swipe is characterised by three movements:
  // 1. move-up (traverse blank spaces). Do this twice to handle edge cases e.g. 0 0 0 2.
  // 2. join-up (same values add together, leaving a blank tile and a single doubled tile).
  // 3. move-up (traverse blank spaces).
  for (int i = 0; i < 4; i++)
    {
      // Do 1 move-up twice:
      for (int twice = 0; twice < 2; twice++)
	{
	  for (int j = 1; j < 4; j++)
	    {
	      if (square[i][j-1] == 0)
		{
		  // In case it's 0 moving into 0 this changes naught!
		  square[i][j-1] = square[i][j];
		  square[i][j] = 0;
		}
	    }
	}
      // Do join-up:
      for (int j = 1; j < 4; j++)
	{
	  if (square[i][j] == square[i][j-1])
	    {
	      square[i][j-1] *= 2;
	      square[i][j] = 0;
	    }
	}
      // Do one final move-up.
      for (int j = 1; j < 4; j++)
	{
	  if (square[i][j-1] == 0)
	    {
	      square[i][j-1] = square[i][j];
	      square[i][j] = 0;
	    }
	}
    }
}

void Game2048::move_right()
{
  for (int i = 0; i < 4; i++)
    {
      for (int twice = 0; twice < 2; twice++)
	{
	  for (int j = 2; j >= 0; j--)
	    {
	      if (square[i][j+1] == 0)
		{
		  square[i][j+1] = square[i][j];
		  square[i][j] = 0;
		}
	    }
	}
      for (int j = 2; j >= 0; j--)
	{
	  if (square[i][j] == square[i][j+1])
	    {
	      square[i][j+1] *= 2;
	      square[i][j] = 0;
	    }
	}
      for (int j = 2; j >= 0; j--)
	{
	  if (square[i][j+1] == 0)
	    {
	      square[i][j+1] = square[i][j];
	      square[i][j] = 0;
	    }
	}
    }
}

void Game2048::move_down()
{
  for (int j = 0; j < 4; j++)
    {
      for (int twice = 0; twice < 2; twice++)
	{
	  for (int i = 2; i >= 0; i--)
	    {
	      if (square[i+1][j] == 0)
		{
		  square[i+1][j] = square[i][j];
		  square[i][j] = 0;
		}
	    }
	}
      for (int i = 2; i >= 0; i--)
	{
	  if (square[i][j] == square[i+1][j])
	    {
	      square[i+1][j] *= 2;
	      square[i][j] = 0;
	    }
	}
      for (int i = 2; i >= 0; i--)
	{
	  if (square[i+1][j] == 0)
	    {
	      square[i+1][j] = square[i][j];
	      square[i][j] = 0;
	    }
	}
    }
}

void Game2048::move_up()
{
  for (int j = 0; j < 4; j++)
    {
      for (int twice = 0; twice < 2; twice++)
	{
	  for (int i = 1; i < 4; i++)
	    {
	      if (square[i-1][j] == 0)
		{
		  square[i-1][j] = square[i][j];
		  square[i][j] = 0;
		}
	    }
	}
      for (int i = 1; i < 4; i++)
	{
	  if (square[i-1][j] == square[i][j])
	    {
	      square[i-1][j] *= 2;
	      square[i][j] = 0;
	    }
	}
      for (int i = 1; i < 4; i++)
	{
	  if (square[i-1][j] == 0)
	    {
	      square[i-1][j] = square[i][j];
	      square[i][j] = 0;
	    }
	}
    }
}

void Game2048::spawn_new()
{
  map<int, int> coords_selector;
  int key_index = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      {
	if (square[i][j] == 0)
	  {
	    coords_selector[key_index] = i * 10 + j;
	    key_index++;
	  }
      }
  // Now key_index holds the number of blank tiles to choose from.
  // Randomly pick one and then extract the row and col of the selected tile:
  int rand_key_index = rand() % key_index;
  int chosen_row, chosen_col;
  chosen_row = coords_selector[rand_key_index] / 10; // Floor division.
  chosen_col = coords_selector[rand_key_index] % 10;
  // Finally, spawn the 2 in that location.
  square[chosen_row][chosen_col] = 2;
}

int Game2048::calculate_score()
{
  int score = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      score += square[i][j];
  return score;
}

bool Game2048::left_possible()
{
  // Check if 'a' left swipe is possible:
  // Scan rightmost tiles (col 4): are the cells in col 3 non-zero and filled with values different
  // from them (element-wise)?
  for (int j = 3; j > 0; j--)
    for (int i = 0; i < 4; i++)
      {
	// There is no need to scan the leftmost column since what is leftmost cannot move left.
	// Hence j the col index decrements down to 1 but not to 0.
	// Check the tile to the left of present tile:
	if (square[i][j] == square[i][j-1] || square[i][j-1] == 0)
	  return true; // Still possible to swipe left, so game is ongoing.
      }
  return false;
}

bool Game2048::right_possible()
{
  // Check if 'd' right swipe is possible:
  for (int j = 0; j < 3; j++)
    for (int i = 0; i < 4; i++)
      {
	if (square[i][j] == square[i][j+1] || square[i][j+1] == 0)
	  return true;
      }
  return false;
}

bool Game2048::down_possible()
{
  // Check if 's' down swipe is possible:
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      {
	if (square[i][j] == square[i+1][j] || square[i+1][j] == 0)
	  return true;
      }
  return false;
}

bool Game2048::up_possible()
{
  // Check if 'w' up swipe is possible:
  for (int i = 3; i > 0; i--)
    for (int j = 0; j < 4; j++)
      {
	if (square[i][j] == square[i-1][j] || square[i-1][j] == 0)
	  return true;
      }
  return false;
}

int Game2048::check_game_status()
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      {
	if (square[i][j] >= 2048)
	  {
	    status = 2;
	    return 2; // Game has been won.
	  }
      }
  // If execution gets to this point, game has not yet been won.
  // Checking for loss condition is complicated: I need to ensure that no direction swipe is possible.
  // Check if left, right, down, or up swipes are possible. If so, game is ongoing (status 0).
  if (left_possible() || right_possible() || down_possible() || up_possible())
    {
      status = 0;
      return 0;
    }
  else
    {
      // If none of the stuff above returned anything, then the game is stuck and player has lost.
      status = 1;
      return 1;
    }
}
