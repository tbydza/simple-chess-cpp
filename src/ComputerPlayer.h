#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <vector>
#include "Player.h"
#include "Move.h"

using namespace std;

/**
 * ComputerPlayer class.
 * implements Player class interface. It represents computer controlled player and his actions.
 */
class ComputerPlayer : public Player
{
public:
  /**
    * ComputerPlayer class constructor.
    */
  ComputerPlayer();

  virtual Move GetMove(const State &gamestate) const override;

protected:
  /**
    * Chooses one Move from the list of moves.
    * @param possibleMoves list of Moves.
    * @return chosen Move
    */
  virtual Move ChooseMove(const vector<Move> &possibleMoves) const;

private:
};

#endif