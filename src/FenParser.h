#ifndef FENPARSER_H
#define FENPARSER_H

#include <string>
#include <sstream>
#include <memory>

#include "State.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"

using namespace std;

/**
 * FenParser class.
 * FEN notation parser. 
 * FEN chess notation is used to store information about chess game state.
 * Used to get data from FEN and to store game data as FEN
 */
class FenParser
{
public:
  /**
 * ReadFEN method will parse string containing game data stored in FEN notation
 * and setup game acordingly
 * @param gamestate stete of the game to be setup
 * @param fen string representation of FEN
 * @returns 0 if parsing successful or -1 in case of parsing error
 */
  int ReadFEN(State &gamestate, const string &fen) const;
  /**
 * WriteFEN method will take state of the game and store it as FEN representation
 * @parama gamestate current state of the game
 * @return string FEN representation of gamestate
 */
  string WriteFEN(const State &gamestate) const;

private:
  vector<string> SplitToTokens(string fen) const;
  void LoadBoard(State &gamestate, const string &token) const;
  void LoadSide(State &gamestate, const string &token) const;
  void LoadCastling(State &gamestate, const string &token) const;
  void LoadEnpassant(State &gamestate, const string &token) const;
  void LoadTurns(State &gamestate, const string &token) const;

  string StoreBoard(const State &gamestate) const;
  string StoreSide(const State &gamestate) const;
  string StoreCastling(const State &gamestate) const;
  string StoreEnpassant(const State &gamestate) const;
  string StoreTurns(const State &gamestate) const;
};

#endif