#ifndef TILE_H
#define TILE_H

#include "Figure.h"

using namespace std;
/**
 * Tile class represents tile of the chessboard.
 */
class Tile
{
public:
  /**
  * Gets pointer to figure standing on the tile or nullptr if the tile is empty
  * @return shared pointer to figure on the tile or nullptr.
  */
  Figure_ GetFigure() const;
  /**
  * Checks if tile is empty
  * @return true if there is some figure on the tile or false if the tile is empty
  */
  bool HasFigure() const;
  /**
  * Sets shared pointer figure to the new value
  * @param figure figure to be placed on the tile.
  */
  void SetFigure(const Figure_ &figure);

private:
  Figure_ figure; /**< smart pointer to figure placed on the tile (nullptr if tile is empty) */
};

#endif