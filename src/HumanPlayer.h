#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "GameController.h"

using namespace std;

/**
 * HUmanPlayer class.
 * implements Player class interface. It represents human controlled player and his actions.
 */
class HumanPlayer : public Player
{
public:
  /**
    * ComputerPlayer class constructor.
    * @param controller pointer to program controller, used UI interraction
    */
  HumanPlayer(const GameController *controller);
  virtual Move GetMove(const State &gamestate) const override;

private:
  const GameController *const controller;
};

#endif