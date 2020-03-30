#include "Pawn.h"

Pawn::Pawn(Side side, const Position &position) : Figure(side, position)
{
    if (side == white)
    {
        actions.push_back(Action(step, 0, 1, moveOnly));
        actions.push_back(Action(step, 1, 1, attackOnly));
        actions.push_back(Action(step, -1, 1, attackOnly));
    }
    else
    {
        actions.push_back(Action(step, 0, -1, moveOnly));
        actions.push_back(Action(step, 1, -1, attackOnly));
        actions.push_back(Action(step, -1, -1, attackOnly));
    }
}

string Pawn::ToString() const
{
    if (side == white)
    {
        return "P";
    }
    else
    {
        return "p";
    }
}

Figure_ Pawn::Clone() const
{
    return Figure_(new Pawn(*this));
}

const vector<Action> Pawn::GetActions() const
{
    vector<Action> actions = Figure::GetActions();
    if (side == white && position.Row() == 2)
    {
        actions.push_back(Action(doubleStep, 0, 2, moveOnly));
    }

    if (side == black && position.Row() == 7)
    {
        actions.push_back(Action(doubleStep, 0, -2, moveOnly));
    }

    return actions;
}
