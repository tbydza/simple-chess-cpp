#ifndef FIGURE_H
#define FIGURE_H

#include "Position.h"
#include "Move.h"
#include "Action.h"

#include <memory>
#include <string>
#include <vector>

using namespace std;

class Figure;
/*
*Figure shared pointer alias.
*/
typedef struct shared_ptr<Figure> Figure_;

/**
 * Side enum.
 * represents side (color) of the chess pieces and the players
 */
enum Side
{
  black,
  white
};

/**
 * Figure class.
 * It represents figure/chess piece on the chess board and its actions.
 * 
 */
class Figure
{
public:
  /**
  * Returns deep copy of itself.
  * @return smart pointer to the clone.
  */
  virtual Figure_ Clone() const = 0;
  /**
    * Class constructor.
    * @param side side of the figure (black or white).
    * @param position position of the figure on the chessboard.
    */
  Figure(Side side, const Position &position);

  virtual ~Figure();
  /**
  * Returns side (color) of the figure.
  * @return side of the figure.
  */
  Side GetSide() const;
  /**
  * Position getter.
  * @return Position of itself.
  */
  const Position &GetPosition() const;
  /**
  * Position setter.
  * @param position new Position.
  */
  void SetPosition(const Position &position);
  /**
  * Returns string representation of the figure.
  * @return string representation of the figure.
  */
  virtual string ToString() const = 0;
  /**
  * Returns list of action defined by the figure.
  * @return list of Actions.
  */
  virtual const vector<Action> GetActions() const;

protected:
  /**
 * Position of the figure on the chessboard
 */
  Position position;
  /**
 * Side of the figure (black or white)
 */
  Side side;
  /**
 * List of standart actions this figure can do  
 */
  vector<Action> actions;
};

#endif