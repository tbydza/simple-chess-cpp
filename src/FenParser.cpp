#include "FenParser.h"

vector<string> FenParser::SplitToTokens(string fen) const
{
    istringstream fenStream(fen);
    string token;
    vector<string> tokens;
    while (fenStream)
    {
        fenStream >> token;
        tokens.push_back(token);
    }
    return tokens;
}

int FenParser::ReadFEN(State &gamestate, const string &fen) const
{
    vector<string> tokens = SplitToTokens(fen);

    try
    {
        LoadBoard(gamestate, tokens.at(0));

        LoadSide(gamestate, tokens.at(1));

        LoadCastling(gamestate, tokens.at(2));

        LoadEnpassant(gamestate, tokens.at(3));

        LoadTurns(gamestate, tokens.at(5));
    }
    catch (const exception &e)
    {
        return -1;
    }
    return 0;
}

void FenParser::LoadBoard(State &gamestate, const string &token) const
{
    int i, j;
    int pos = 0;
    for (size_t k = 0; k < token.length(); ++k)
    {
        char letter = token.at(k);

        j = pos % 8;
        i = 8 - (pos / 8) - 1;
        Position tilePosition(j, i);

        switch (letter)
        {
        case 'p':
            gamestate.AddFigure(make_shared<Pawn>(black, tilePosition));
            break;
        case 'r':
            gamestate.AddFigure(make_shared<Rook>(black, tilePosition));
            break;
        case 'n':
            gamestate.AddFigure(make_shared<Knight>(black, tilePosition));
            break;
        case 'b':
            gamestate.AddFigure(make_shared<Bishop>(black, tilePosition));
            break;
        case 'q':
            gamestate.AddFigure(make_shared<Queen>(black, tilePosition));
            break;
        case 'k':
            gamestate.AddFigure(make_shared<King>(black, tilePosition));
            break;
        case 'P':
            gamestate.AddFigure(make_shared<Pawn>(white, tilePosition));
            break;
        case 'R':
            gamestate.AddFigure(make_shared<Rook>(white, tilePosition));
            break;
        case 'N':
            gamestate.AddFigure(make_shared<Knight>(white, tilePosition));
            break;
        case 'B':
            gamestate.AddFigure(make_shared<Bishop>(white, tilePosition));
            break;
        case 'Q':
            gamestate.AddFigure(make_shared<Queen>(white, tilePosition));
            break;
        case 'K':
            gamestate.AddFigure(make_shared<King>(white, tilePosition));
            break;
        case '/':
            pos--;
            break;
        case '1':
            break;
        case '2':
            pos++;
            break;
        case '3':
            pos += 2;
            break;
        case '4':
            pos += 3;
            break;
        case '5':
            pos += 4;
            break;
        case '6':
            pos += 5;
            break;
        case '7':
            pos += 6;
            break;
        case '8':
            pos += 7;
            break;
        default:
            throw exception();
        }
        pos++;
    }
}
void FenParser::LoadSide(State &gamestate, const string &token) const
{
    if (token == "w")
    {
        gamestate.SetSideOnTurn(white);
    }
    else if (token == "b")
    {
        gamestate.SetSideOnTurn(black);
    }
    else
    {
        throw exception();
    }
}
void FenParser::LoadCastling(State &gamestate, const string &token) const
{
    gamestate.SetCastlingKingsideWhite(false);
    gamestate.SetCastlingQueensideWhite(false);
    gamestate.SetCastlingKingsideBlack(false);
    gamestate.SetCastlingQueensideBlack(false);

    if (token.find('K') != string::npos)
    {
        gamestate.SetCastlingKingsideWhite(true);
    }
    if (token.find('Q') != string::npos)
    {
        gamestate.SetCastlingQueensideWhite(true);
    }
    if (token.find('k') != string::npos)
    {
        gamestate.SetCastlingKingsideBlack(true);
    }
    if (token.find('q') != string::npos)
    {
        gamestate.SetCastlingQueensideBlack(true);
    }
}
void FenParser::LoadEnpassant(State &gamestate, const string &token) const
{
    if (token == "-")
    {
        gamestate.SetEnpassantActive(false);
    }
    else
    {
        try
        {
            gamestate.SetEnpassantPosition(Position(token));
            gamestate.SetEnpassantActive(true);
        }
        catch (const exception &e)
        {
            throw exception();
        }
    }
}
void FenParser::LoadTurns(State &gamestate, const string &token) const
{
    gamestate.SetTurnCount(stoi(token, nullptr));
}

string FenParser::WriteFEN(const State &gamestate) const
{
    string result("");

    result.append(StoreBoard(gamestate));
    result.append(" ");
    result.append(StoreSide(gamestate));
    result.append(" ");
    result.append(StoreCastling(gamestate));
    result.append(" ");
    result.append(StoreEnpassant(gamestate));
    result.append(" ");
    result.append("0");
    result.append(" ");
    result.append(StoreTurns(gamestate));

    return result;
}

string FenParser::StoreBoard(const State &gamestate) const
{
    string result("");
    for (int i = 7; i >= 0; --i)
    {
        int spaceCnt = 0;
        for (int j = 0; j < 8; ++j)
        {
            if (!gamestate.getTile(Position(j, i)).HasFigure())
            {
                spaceCnt++;
            }
            else
            {
                if (spaceCnt != 0)
                {
                    result.append(to_string(spaceCnt));
                }
                spaceCnt = 0;
                result.append(gamestate.getTile(Position(j, i)).GetFigure()->ToString());
            }
        }

        if (spaceCnt != 0)
        {
            result.append(to_string(spaceCnt));
        }
        if (i != 0)
        {
            result.append("/");
        }
    }
    return result;
}
string FenParser::StoreSide(const State &gamestate) const
{
    string result("");

    if (gamestate.GetSideOnTurn() == white)
    {
        result = "w";
    }
    else
    {
        result = "b";
    }
    return result;
}
string FenParser::StoreCastling(const State &gamestate) const
{
    string result;
    if (gamestate.GetCastlingKingsideWhite())
    {
        result.append("K");
    }
    if (gamestate.GetCastlingQueensideWhite())
    {
        result.append("Q");
    }
    if (gamestate.GetCastlingKingsideBlack())
    {
        result.append("k");
    }
    if (gamestate.GetCastlingQueensideBlack())
    {
        result.append("q");
    }

    if (result.empty())
    {
        result.append("-");
    }
    return result;
}

string FenParser::StoreEnpassant(const State &gamestate) const
{
    string result("");

    if (!gamestate.IsEnpassantActive())
    {
        result = "-";
    }
    else
    {
        result = gamestate.GetEnpassantPosition().ToString();
    }

    return result;
}
string FenParser::StoreTurns(const State &gamestate) const
{
    string result("");

    result = to_string(gamestate.GetTurnCount());

    return result;
}
