#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <vector>
#include "Move.h"
#include "State.h"

using namespace std;

class Player;
typedef struct shared_ptr<Player> Player_;

class Player
{
public:
  Player();
  virtual ~Player();
  /**
    * Gets move chosen by the player.
    * @param gamestate gamestate reference.
    * @return chosen Move
    */
  virtual Move GetMove(const State &gamestate) const = 0;

protected:
private:
};

#endif