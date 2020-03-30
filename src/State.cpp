#include "State.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include <algorithm>

State::State() : enpassantPosition(Position(0, 0))
{
    board.resize(8);
    for (int i = 0; i < 8; ++i)
    {
        board.at(i).reserve(8);
        for (int j = 0; j < 8; ++j)
        {
            board.at(i).push_back(Tile());
        }
    }
    enpassantActive = false;
}

State::State(const State &src) : enpassantPosition(src.enpassantPosition)
{
    enpassantActive = src.enpassantActive;

    castlingKingsideBlack = src.castlingKingsideBlack;
    castlingKingsideWhite = src.castlingKingsideWhite;
    castlingQueensideBlack = src.castlingQueensideBlack;
    castlingQueensideWhite = src.castlingQueensideWhite;

    turnCount = src.turnCount;
    sideOnTurn = src.sideOnTurn;

    board.resize(8);
    for (int i = 0; i < 8; ++i)
    {
        board.at(i).reserve(8);
        for (int j = 0; j < 8; ++j)
        {
            board.at(i).push_back(Tile());
        }
    }

    for (auto &figure : src.whiteFigures)
    {
        this->AddFigure(figure->Clone());
    }
    for (auto &figure : src.blackFigures)
    {
        this->AddFigure(figure->Clone());
    }
}

void State::AddFigure(const Figure_ &figure)
{
    getTile(figure->GetPosition()).SetFigure(figure);
    if (figure->GetSide() == white)
    {
        whiteFigures.insert(figure);
    }
    else
    {
        blackFigures.insert(figure);
    }
}

Tile &State::getTile(const Position &pos)
{
    return board.at(pos.GetY()).at(pos.GetX());
}

const Tile &State::getTile(const Position &pos) const
{
    return board.at(pos.GetY()).at(pos.GetX());
}

vector<Move> State::GetListOfMoves(Side side, bool validate) const
{
    vector<Move> result;
    if (side == white)
    {

        for (auto &figure : whiteFigures)
        {
            vector<Move> moves = GetListOfMoves(figure, validate);
            result.insert(result.end(), moves.begin(), moves.end());
        }
    }
    else
    {
        for (auto &figure : blackFigures)
        {
            vector<Move> moves = GetListOfMoves(figure, validate);
            result.insert(result.end(), moves.begin(), moves.end());
        }
    }
    return result;
}

vector<Move> State::GetListOfMoves(bool validate) const
{
    return GetListOfMoves(sideOnTurn, validate);
}

void State::PlaceFigure(Figure_ figure, Position destination)
{
    getTile(figure->GetPosition()).SetFigure(nullptr);

    figure->SetPosition(destination);
    getTile(destination).SetFigure(figure);
}

void State::ExecuteCastling(const Move &move)
{
    Figure_ figure = getTile(move.GetSourcePosition()).GetFigure();
    Figure_ rook;
    if (move.GetSourcePosition().GetX() < move.GetDestinationPosition().GetX())
    {
        rook = getTile(Position(7, figure->GetPosition().GetY())).GetFigure();
        PlaceFigure(rook, Position(rook->GetPosition().GetX() - 2, rook->GetPosition().GetY()));
    }
    else
    {
        rook = getTile(Position(0, figure->GetPosition().GetY())).GetFigure();
        PlaceFigure(rook, Position(rook->GetPosition().GetX() + 3, rook->GetPosition().GetY()));
    }

    if (sideOnTurn == white)
    {
        castlingKingsideWhite = false;
        castlingQueensideWhite = false;
    }
    else
    {
        castlingKingsideBlack = false;
        castlingQueensideBlack = false;
    }
}

void State::ExecuteCapture(const Move &move)
{
    Figure_ figure = getTile(move.GetSourcePosition()).GetFigure();
    Figure_ enemyFigure;

    if (move.GetDestinationPosition() == enpassantPosition)
    {
        if (sideOnTurn == white)
        {
            enemyFigure = getTile(Position(
                                      move.GetDestinationPosition().GetX(),
                                      move.GetDestinationPosition().GetY() + 1))
                              .GetFigure();
        }
        else
        {
            enemyFigure = getTile(Position(
                                      move.GetDestinationPosition().GetX(),
                                      move.GetDestinationPosition().GetY() - 1))
                              .GetFigure();
        }
    }
    else
    {
        enemyFigure = getTile(move.GetDestinationPosition()).GetFigure();
    }

    if (sideOnTurn == white)
    {
        blackFigures.erase(enemyFigure);
    }
    else
    {
        whiteFigures.erase(enemyFigure);
    }

    getTile(enemyFigure->GetPosition()).SetFigure(nullptr);
}

void State::ExecuteMove(const Move &move)
{
    enpassantActive = false;
    Figure_ figure = getTile(move.GetSourcePosition()).GetFigure();

    if (move.IsCastling())
    {
        ExecuteCastling(move);
    }

    if (move.IsCapture())
    {
        ExecuteCapture(move);
    }

    PlaceFigure(figure, move.GetDestinationPosition());

    //in case of pawn move set en passant
    if (dynamic_cast<Pawn *>(figure.get()) != nullptr)
    {
        if (!move.GetSourcePosition().IsNextTo(move.GetDestinationPosition()))
        {
            enpassantPosition =
                Position(move.GetSourcePosition().GetX(),
                         (move.GetDestinationPosition().GetY() + move.GetSourcePosition().GetY()) / 2);

            enpassantActive = true;
        }

        if ((figure->GetSide() == white && figure->GetPosition().Row() == 8) ||
            (figure->GetSide() == black && figure->GetPosition().Row() == 1))
        {
            getTile(figure->GetPosition())
                .SetFigure(make_shared<Queen>(figure->GetSide(), figure->GetPosition()));
        }
    }

    //in case of rook move update castling rights
    if (dynamic_cast<Rook *>(figure.get()) != nullptr)
    {

        if (move.GetSourcePosition() == Position(7, 0))
        {
            castlingKingsideWhite = false;
        }
        if (move.GetSourcePosition() == Position(0, 0))
        {
            castlingQueensideWhite = false;
        }
        if (move.GetSourcePosition() == Position(7, 0))
        {
            castlingQueensideBlack = false;
        }
        if (move.GetSourcePosition() == Position(7, 7))
        {
            castlingKingsideBlack = false;
        }
    }

    //in case of king move update castling rights
    if (dynamic_cast<King *>(figure.get()) != nullptr)
    {
        if (figure->GetSide() == white)
        {
            castlingKingsideWhite = false;
            castlingQueensideWhite = false;
        }
        else
        {
            castlingKingsideBlack = false;
            castlingQueensideBlack = false;
        }
    }

    EndTurn();
}

void State::EndTurn()
{
    if (sideOnTurn == white)
    {
        sideOnTurn = black;
    }
    else
    {
        sideOnTurn = white;
        turnCount++;
    }
}

vector<Move> State::GenerateMovesFromShiftAction(const Figure_ &figure, const Action &action) const
{
    vector<Move> result;
    Position start = figure->GetPosition();
    Position target = start;
    while (true)
    {

        try
        {
            target = target + action.GetDirection();
        }
        catch (const exception &e)
        {
            //target out of boundaries of the chessboard
            break;
        }

        if (!getTile(target).HasFigure())
        {
            result.push_back(Move(start, target, false));
        }
        else
        {
            if (getTile(target).GetFigure()->GetSide() != figure->GetSide())
            {
                result.push_back(Move(start, target, true));
                break;
            }
            else
            {
                break;
            }
        }
    }
    return result;
}

Move State::GenerateMoveFromStepAction(const Figure_ &figure, const Action &action) const
{
    Position start = figure->GetPosition();
    Position target = start;
    try
    {
        target = start + action.GetDirection();
    }
    catch (const exception &e)
    {
        //target out of boundaries of the chessboard
        throw exception();
    }

    switch (action.GetActionType())
    {
    case moveOnly:
        if (action.GetMoveType() == doubleStep)
        {
            Position interPosition(target.GetX(), (target.GetY() + start.GetY()) / 2);
            if (!getTile(target).HasFigure() &&
                !getTile(interPosition).HasFigure())
            {
                return (Move(start, target, false));
            }
        }
        else
        {
            if (!getTile(target).HasFigure())
            {
                return (Move(start, target, false));
            }
        }

        break;
    case attackOnly:
        if (getTile(target).HasFigure() &&
            getTile(target).GetFigure()->GetSide() != figure->GetSide())
        {
            return (Move(start, target, true));
        }
        if (enpassantActive && target == enpassantPosition &&
            dynamic_cast<Pawn *>(figure.get()) != nullptr)
        {
            return (Move(start, target, true));
        }

        break;
    case moveOrAttack:
        if (!getTile(target).HasFigure())
        {
            return (Move(start, target, false));
        }
        else
        {
            if (getTile(target).GetFigure()->GetSide() != figure->GetSide())
            {
                return (Move(start, target, true));
            }
        }

        break;
    }
    //no move generated
    throw exception();
}

vector<Move> State::GetListOfMoves(const Figure_ &figure, bool validate) const
{
    vector<Move> result;
    for (auto &action : figure->GetActions())
    {

        if (action.GetMoveType() == shift)
        {
            vector<Move> moves = GenerateMovesFromShiftAction(figure, action);
            result.insert(result.end(), moves.begin(), moves.end());
        }
        else
        {

            try
            {
                result.push_back(GenerateMoveFromStepAction(figure, action));
            }
            catch (const exception &e)
            {
                //no move from this action generated
                continue;
            }
        }
    }

    //if figure is king, generate castlig moves
    if (dynamic_cast<King *>(figure.get()) != nullptr)
    {
        Position kingPosition = figure->GetPosition();
        if (CanCastleKingSide(figure))
        {
            result.push_back(
                Move(kingPosition, Position(kingPosition.GetX() + 2, kingPosition.GetY()), false, true));
        }
        if (CanCastleQueenSide(figure))
        {
            result.push_back(
                Move(kingPosition, Position(kingPosition.GetX() - 2, kingPosition.GetY()), false, true));
        }
    }

    if (validate)
    {
        vector<Move> validResults;
        for (auto &move : result)
        {
            if (IsValidMove(move))
            {
                validResults.push_back(move);
            }
        }
        return validResults;
    }
    else
    {
        return result;
    }
}

bool State::CanCastleKingSide(const Figure_ &figure) const
{
    if (figure->GetSide() == white)
    {
        if (!castlingKingsideWhite)
        {
            return false;
        }
    }
    else
    {
        if (!castlingKingsideBlack)
        {
            return false;
        }
    }

    Position kingPosition = figure->GetPosition();
    if ((getTile(Position(kingPosition.GetX() + 1, kingPosition.GetY()))).HasFigure() ||
        (getTile(Position(kingPosition.GetX() + 2, kingPosition.GetY()))).HasFigure())
    {
        return false;
    }

    return true;
}
bool State::CanCastleQueenSide(const Figure_ &figure) const
{
    if (figure->GetSide() == white)
    {
        if (!castlingQueensideWhite)
        {
            return false;
        }
    }
    else
    {
        if (!castlingQueensideBlack)
        {
            return false;
        }
    }

    Position kingPosition = figure->GetPosition();
    if ((getTile(Position(kingPosition.GetX() - 1, kingPosition.GetY()))).HasFigure() ||
        (getTile(Position(kingPosition.GetX() - 2, kingPosition.GetY()))).HasFigure() ||
        (getTile(Position(kingPosition.GetX() - 3, kingPosition.GetY()))).HasFigure())
    {
        return false;
    }

    return true;
}

bool State::IsValidMove(const Move &move) const
{
    //create copy of gamestate, execute move and check validity

    State newState(*this);

    newState.ExecuteMove(move);

    Figure_ kingFigure;

    //find king figure
    if (sideOnTurn == white)
    {
        for (auto &figure : newState.whiteFigures)
        {
            if (dynamic_cast<King *>(figure.get()) != nullptr)
            {
                kingFigure = figure;
                break;
            }
        }
    }
    else
    {
        for (auto &figure : newState.blackFigures)
        {
            if (dynamic_cast<King *>(figure.get()) != nullptr)
            {
                kingFigure = figure;
                break;
            }
        }
    }

    //check for check mate
    if (newState.IsFigureAttacked(kingFigure))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool State::IsFigureAttacked(const Figure_ &figure) const
{

    vector<Move> moves = GetListOfMoves(false);

    for (auto &move : moves)
    {
        if (move.IsCapture() &&
            move.GetDestinationPosition() == figure->GetPosition())
        {

            return true;
        }
    }

    return false;
}

void State::SetEnpassantPosition(const Position &pos)
{
    enpassantPosition = pos;
}
void State::SetEnpassantActive(bool active)
{
    enpassantActive = active;
}
void State::SetCastlingKingsideBlack(bool castlingKingsideBlack)
{
    this->castlingKingsideBlack = castlingKingsideBlack;
}
void State::SetCastlingKingsideWhite(bool castlingKingsideWhite)
{
    this->castlingKingsideWhite = castlingKingsideWhite;
}
void State::SetCastlingQueensideBlack(bool castlingQueensideBlack)
{
    this->castlingQueensideBlack = castlingQueensideBlack;
}
void State::SetCastlingQueensideWhite(bool castlingQueensideWhite)
{
    this->castlingQueensideWhite = castlingQueensideWhite;
}
void State::SetTurnCount(unsigned int count)
{
    turnCount = count;
}
void State::SetSideOnTurn(Side side)
{
    sideOnTurn = side;
}

const Position &State::GetEnpassantPosition() const
{
    return enpassantPosition;
}
bool State::IsEnpassantActive() const
{
    return enpassantActive;
}
bool State::GetCastlingKingsideBlack() const
{
    return castlingKingsideBlack;
}
bool State::GetCastlingKingsideWhite() const
{
    return castlingKingsideWhite;
}
bool State::GetCastlingQueensideBlack() const
{
    return castlingQueensideBlack;
}
bool State::GetCastlingQueensideWhite() const
{
    return castlingQueensideWhite;
}
unsigned int State::GetTurnCount() const
{
    return turnCount;
}
Side State::GetSideOnTurn() const
{
    return sideOnTurn;
}