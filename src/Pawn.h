#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"

using namespace std;
/**
 * Pawn class.
 * Inherits from Figure class. It represents Pawn chess piece.
 */
class Pawn : public Figure
{
public:
/**
    * Class constructor.
    * @param side side of the figure (black or white).
    * @param position position of the figure on the chessboard.
    */
  Pawn(Side side, const Position &position);
  string ToString() const override;
  Figure_ Clone() const override;
  const vector<Action> GetActions() const override;

private:
};

#endif