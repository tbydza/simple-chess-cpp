#ifndef UI_H
#define UI_H

#include "State.h"

class GameController;

class UI;
typedef struct shared_ptr<UI> UI_;

using namespace std;

/**
  * UI class
  * UI abstract class serves as interface for user interfaces
  */
class UI
{
public:
  /**
  * UI class constructor
  * @param controller pointer to program controller.
  */
  UI(GameController *controller);
  /**
  * This will get current gamestate and render it on screen accordingly
  * @param GameState gamestate used to get current info to render them.
  */
  virtual void RenderGamestate(const State &GameState) const = 0;
  /**
  * This will render game over notification with winning side
  * @param winner winning side
  */
  virtual void RenderGameOver(const string &winner) const = 0;
  /**
  * This method will get player command and calls apropriete methods
  */
  virtual void GameInteraction() = 0;
  /**
  * This method is used to close running UI
  */
  virtual void CloseUI() = 0;
  /**
  * This method opens starts UI
  */
  virtual void OpenUI() = 0;
  virtual ~UI();

protected:
  /**
 * controller pointer to the main controller (GameController) of the program 
 * (used to comunicate with UI and interract with human players)
 */
  GameController *const controller;

private:
};

#endif