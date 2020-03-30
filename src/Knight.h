#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"

using namespace std;
/**
 * Knight class.
 * Inherits from Figure class. It represents Knight chess piece.
 */
class Knight : public Figure
{
public:
  /**
  * Class constructor.
  * @param side side of the figure (black or white).
  * @param position position of the figure on the chessboard.
  */
  Knight(Side side, const Position &position);
  string ToString() const override;
  Figure_ Clone() const override;

private:
};

#endif