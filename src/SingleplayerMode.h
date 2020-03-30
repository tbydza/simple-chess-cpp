#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include "GameMode.h"

using namespace std;
/**
 * SingleplayerMode class.
 * This class represents singleplayer GameMode agains AI opponent.
 * This inherites from GameMode class. 
 * 
 */
class SingleplayerMode : public GameMode
{
public:
/**
 * SingleplayerMode class constructor.
 * @param controller pointer to the main controller of the program 
 * (used to comunicate with UI and interract with human players)
 * @param whitePlayer white Player (shared pointer to Player object) 
 * @param blackPlayer black Player(shared pointer to Player object)
 */
  SingleplayerMode(const GameController *controller, const Player_ &white, const Player_ &black);

private:
};

#endif