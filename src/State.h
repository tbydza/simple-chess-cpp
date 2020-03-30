#ifndef STATE_H
#define STATE_H

#include "Figure.h"
#include "Tile.h"
#include "Position.h"
#include "Move.h"
#include <vector>
#include <set>

using namespace std;

/**
  * State class.
  * This is the most important class of the program, this class holds all game data and serves as game engine.
  * This class allows access to game data, generate moves based on the state of the game, execute moves,
  * validate moves, checks for Check and Check mate, manages the figures and count turns
  */
class State
{
public:
  /**
  * State class constructor
  */
  State();
  /**
  * Copy constructor
  */
  State(const State &src);
  /**
  * allows acces to tiles of the board
  * @param pos Position of the tile. 
  * @return Tile at pos Position .
  */
  Tile &getTile(const Position &pos);
  /**
  * allows acces to tiles of the board
  * @param pos Position of the tile. 
  * @return Tile at pos Position .
  */
  const Tile &getTile(const Position &pos) const;
  /**
  * This will take valid move and will execute it and update properties of the board besed on the move
  * @param move move to be executed
  */
  void ExecuteMove(const Move &move);
  /**
  * This method generates list of all possible moves of the side currently on turn
  * @param validate filter out invalid moves (end in Check), default value = true
  * @return list of possible moves
  */
  vector<Move> GetListOfMoves(bool validate = true) const;
  /**
  * This method generates list of all possible moves of one playing side
  * @param side Side for which to generate moves
  * @param validate filter out invalid moves (end in Check), default value = true
  * @return list of possible moves
  */
  vector<Move> GetListOfMoves(Side side, bool validate = true) const;
  /**
  * This method generates list of all possible moves of one figure
  * @param validate filter out invalid moves (end in Check), default value = true
  * @return list of possible moves
  */
  vector<Move> GetListOfMoves(const Figure_ &figure, bool validate = true) const;
  /**
  * AddFigure method will add (new) figure on the board
  * @param figure to be added
  */
  void AddFigure(const Figure_ &figure);

  /**
  * EnpassantPosition setter.
  * @param pos new EnpassantPosition value.
  */
  void SetEnpassantPosition(const Position &pos);
  /**
  * enpassantActive setter.
  * @param active new enpassantActive value.
  */
  void SetEnpassantActive(bool active);
  /**
  * castlingKingsideBlack setter.
  * @param castlingKingsideBlack new castlingKingsideBlack value.
  */
  void SetCastlingKingsideBlack(bool castlingKingsideBlack);
  /**
  * castlingKingsideWhite setter.
  * @param castlingKingsideWhite new castlingKingsideWhite value.
  */
  void SetCastlingKingsideWhite(bool castlingKingsideWhite);
  /**
  * castlingQueensideBlack setter.
  * @param castlingQueensideBlack new castlingQueensideBlack value.
  */
  void SetCastlingQueensideBlack(bool castlingQueensideBlack);
  /**
  * castlingQueensideWhite setter.
  * @param castlingQueensideWhite new castlingQueensideWhite value.
  */
  void SetCastlingQueensideWhite(bool castlingQueensideWhite);
  /**
  * turnCount setter.
  * @param count new turnCount value.
  */
  void SetTurnCount(unsigned int count);
  /**
  * sideOnTurn setter.
  * @param side new sideOnTurn value.
  */
  void SetSideOnTurn(Side side);

  /**
  * EnpassantPosition getter.
  * @return EnpassantPosition value.
  */
  const Position &GetEnpassantPosition() const;
  /**
  * EnpassantActive getter.
  * @return EnpassantActive value.
  */
  bool IsEnpassantActive() const;
  /**
  * castlingKingsideBlack getter.
  * @return castlingKingsideBlack value.
  */
  bool GetCastlingKingsideBlack() const;
  /**
  * castlingKingsideWhite getter.
  * @return castlingKingsideWhite value.
  */
  bool GetCastlingKingsideWhite() const;
  /**
  * castlingQueensideBlack getter.
  * @return castlingQueensideBlack value.
  */
  bool GetCastlingQueensideBlack() const;
  /**
  * castlingQueensideWhite getter.
  * @return castlingQueensideWhite value.
  */
  bool GetCastlingQueensideWhite() const;
  /**
  * turnCount getter.
  * @return turnCount value.
  */
  unsigned int GetTurnCount() const;
  /**
  * sideOnTurn getter.
  * @return sideOnTurn value.
  */
  Side GetSideOnTurn() const;

private:
  vector<vector<Tile>> board;              /**< matrix of Tiles representing chessboard */
  set<Figure_> blackFigures, whiteFigures; /**< lists of figures in the game */

  void EndTurn();                                         /**< End turn, switch sides, count turns */
  void PlaceFigure(Figure_ figure, Position destination); /**< moves figure to the destination */
  bool CanCastleKingSide(const Figure_ &figure) const;    /**< is castling on kingside possible */
  bool CanCastleQueenSide(const Figure_ &figure) const;   /**< is castling on queenside possible */
  bool IsValidMove(const Move &move) const;               /**< check if turn will not end in check state */
  bool IsFigureAttacked(const Figure_ &figure) const;     /**< check if figure could be captured */
  void ExecuteCastling(const Move &move);                 /**< execute castling part of the move*/
  void ExecuteCapture(const Move &move);                  /**< execute capture part of the move */

  vector<Move> GenerateMovesFromShiftAction(const Figure_ &figure, const Action &action) const;
  Move GenerateMoveFromStepAction(const Figure_ &figure, const Action &action) const;

  Position enpassantPosition;   /**< en passant position */
  bool enpassantActive = false; /**< en passant capture is possible and en passant position is valid*/
  bool castlingKingsideBlack;   /**< kingside castling right of the black player */
  bool castlingKingsideWhite;   /**< kingside castling right of the white player */
  bool castlingQueensideBlack;  /**< queenside castling right of the black player */
  bool castlingQueensideWhite;  /**< queenside castling right of the white player */
  unsigned int turnCount;       /**< number of the current turn */
  Side sideOnTurn;              /**< Side (color) of player currently on turn*/
};

#endif