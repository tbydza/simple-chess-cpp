#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"

using namespace std;
/**
 * Queen class.
 * Inherits from Figure class. It represents Queen chess piece.
 */
class Queen : public Figure
{
public:
  /**
    * Class constructor.
    * @param side side of the figure (black or white).
    * @param position position of the figure on the chessboard.
    */
  Queen(Side side, const Position &position);
  string ToString() const override;
  Figure_ Clone() const override;

private:
};

#endif