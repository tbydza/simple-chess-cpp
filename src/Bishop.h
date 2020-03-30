#ifndef BISHOP_H
#define BISHOP_H

#include "Figure.h"

using namespace std;

/**
 * Bishop class.
 * Inherits from Figure class. It represents Bishop chess piece.
 */
class Bishop : public Figure
{
public:
  /**
    * Class constructor.
    * @param side side of the figure (black or white).
    * @param position position of the figure on the chessboard.
    */
  Bishop(Side side, const Position &position);

  string ToString() const override;

  Figure_ Clone() const override;

private:
};

#endif