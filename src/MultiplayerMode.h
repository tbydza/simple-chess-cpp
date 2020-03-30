#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include "GameMode.h"

using namespace std;
/**
 * MultiplayerMode class.
 * This class represents local multiplayer GameMode on one machine.
 * This inherites from GameMode class. 
 * 
 */
class MultiplayerMode : public GameMode
{
public:
/**
 * MultiplayerMode class constructor.
 * @param controller pointer to the main controller of the program 
 * (used to comunicate with UI and interract with human players)
 * @param whitePlayer white Player (shared pointer to Player object) 
 * @param blackPlayer black Player(shared pointer to Player object)
 */
  MultiplayerMode(const GameController *controller, const Player_ &white, const Player_ &black);

private:
};

#endif