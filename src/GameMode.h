#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "Player.h"
#include "State.h"
#include "FenParser.h"

class GameController;

class GameMode;
typedef struct shared_ptr<GameMode> GameMode_;

using namespace std;

/**
 * GameMode abstract class.
 * This class represents game mode (singleplayer / multiplayer).
 * It contains gamestate data, players representations  
 * and methods to setup and run game.
 * 
 */
class GameMode
{
public:
/**
 * GameMode class constructor.
 * @param controller pointer to the main controller of the program 
 * @param whitePlayer white Player (shared pointer to Player object) 
 * @param blackPlayer black Player(shared pointer to Player object)
 */
  GameMode(const GameController *controller, const Player_ &whitePlayer, const Player_ &blackPlayer);
  /**
 * Run method will run the main game loop of player making turns.
 */
  void Run();
  /**
 * Stop method stops the game and exit game loop
 */
  void Stop();
  /**
 * game state getter
 * @return State of the current game
 */
  const State &GetGameState() const;
  /**
 * Setup method setups the gamestate of the game from game state data in FEN notation
 * @param fen string representattion of the game state (default value is standart chess initial value)
 */
  void Setup(const string &fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  /**
 * GetFenRepresentation method will create fen representation of the current gamestate
 * @return fen representation of the current game as string
 */
  string GetFenRepresentation();
  virtual ~GameMode();
  /**
 * Checks if game is running or not
 * @return true if game is in progress or false otherwise
 */
  bool IsGameRunning();

protected:
  /**
 * EndTurn method will end turn for one player and start turn for the other one
 */
  void EndTurn();
  /**
 * controller pointer to the main controller (GameController) of the program 
 * (used to comunicate with UI and interract with human players)
 */
  const GameController *const controller;
  /**
 * shared pointer to Player representing white player
 */
  Player_ whitePlayer;
  /**
 * shared pointer to Player representing balck player
 */
  Player_ blackPlayer;
  /**
 * shared pointer to Player who is currently on turn
 */
  Player_ playerOnTurn;
  /**
 * State of the game
 */
  State gamestate;
  /**
 * boolean signal start and stop of the game
 */
  bool gameRunning;
};

#endif