#ifndef KING_H
#define KING_H

#include "Figure.h"

using namespace std;
/**
 * King class.
 * Inherits from Figure class. It represents King chess piece.
 */
class King : public Figure
{
public:
  /**
    * Class constructor.
    * @param side side of the figure (black or white).
    * @param position position of the figure on the chessboard.
    */
  King(Side side, const Position &position);
  string ToString() const override;
  Figure_ Clone() const override;

private:
};

#endif