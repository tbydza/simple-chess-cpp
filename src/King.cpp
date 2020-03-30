#include "King.h"

King::King(Side side, const Position &position) : Figure(side, position)
{
    actions.push_back(Action(step, 1, 0));
    actions.push_back(Action(step, 0, 1));
    actions.push_back(Action(step, 1, 1));

    actions.push_back(Action(step, -1, 0));
    actions.push_back(Action(step, 0, -1));
    actions.push_back(Action(step, -1, -1));

    actions.push_back(Action(step, -1, 1));
    actions.push_back(Action(step, 1, -1));
}

string King::ToString() const
{
    if (side == white)
    {
        return "K";
    }
    else
    {
        return "k";
    }
}

Figure_ King::Clone() const
{
    return Figure_(new King(*this));
}
