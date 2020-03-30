#include "Knight.h"

Knight::Knight(Side side, const Position &position) : Figure(side, position)
{
    actions.push_back(Action(step, 1, 2));
    actions.push_back(Action(step, -1, 2));
    actions.push_back(Action(step, 1, -2));
    actions.push_back(Action(step, -1, -2));

    actions.push_back(Action(step, 2, 1));
    actions.push_back(Action(step, -2, 1));
    actions.push_back(Action(step, 2, -1));
    actions.push_back(Action(step, -2, -1));
}

string Knight::ToString() const
{
    if (side == white)
    {
        return "N";
    }
    else
    {
        return "n";
    }
}

Figure_ Knight::Clone() const
{
    return Figure_(new Knight(*this));
}
