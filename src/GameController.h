#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <algorithm>

#include "State.h"
#include "MultiplayerMode.h"
#include "SingleplayerMode.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "SimpleConsoleUI.h"
#include "FileIO.h"

using namespace std;

/**
 * GameController class.
 * This program has MVP architecture and this class is Presenter connecting Model (GameMode)
 * and View (UI) and allows communication.
 * This class conntects other parts of the program and is used to controll them 
 * and allow them to comunicate between each other.
 */
class GameController
{
public:
  /**
 * Class constructor. Intializes controller.
 */
  GameController();
  /**
 * This will quit the game returns controll back to main menu
 */
  void QuitGame();
  /**
 * ExitProgram method will quit the game and close UI and exits.
 */
  void ExitProgram();
  /**
 * This method will start UI (it opens main menu)
 */
  void StartProgram();
  /**
 * This will get updated chessboard and calls UI to render it.
 */
  void UpdateBoard() const;
  /**
 * This will intitialize and start new game.
 * @param multiplayerEnable if true start multiplayer game, else start singleplayer game
 */
  void NewGame(bool multiplayerEnable);
  /**
 * This try to create valid move based on the positions provided by the human player
 * @param src source Position of wanted move
 * @param dst destination Position of wanted move
 * @return true if Move was generated or false if Move is invalid
 */
  bool GeneratePlayerMove(const Position &src, const Position &dst);
  /**
 * This will call UI to interract with player and get Move chosen by the player
 * @return Move chosen by human player
 */
  Move GetPlayerInput() const;
  /**
 * This method calls UI to render game over notification
 * @param winningSide Side which has won the game
 */
  void SignalGameOver(Side winningSide) const;
  /**
  * This will save current game to savefile
  * @param fileName savefile name
  */
  bool SaveGame(const string &fileName) const;
  /**
  * This will load game data from savefile and intitialize the game with it and start the game
  * @param fileName savefile name
  */
  bool LoadGame(const string &fileName);

private:
  Move playerMoveCache; /**< Move that was generated from user command, ready to be passed to game engine */
  UI_ interface;        /**< shared pointer to user interface */
  GameMode_ game;       /**< shared pointer to game engine */
  const string pvp = "PvP";
  const string pve = "PvE";
};

#endif