#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"

using namespace std;
/**
 * Rook class.
 * Inherits from Figure class. It represents Rook chess piece.
 */
class Rook : public Figure
{
public:
  /**
    * Class constructor.
    * @param side side of the figure (black or white).
    * @param position position of the figure on the chessboard.
    */
  Rook(Side side, const Position &position);
  string ToString() const override;
  Figure_ Clone() const override;

private:
};

#endif