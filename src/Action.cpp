#include "Action.h"

Action::Action(MoveType moveType, int x, int y, ActionType actionType)
{
    this->moveType = moveType;
    direction.first = x;
    direction.second = y;
    this->actionType = actionType;
}

MoveType Action::GetMoveType() const
{
    return moveType;
}

ActionType Action::GetActionType() const
{
    return actionType;
}
pair<int, int> Action::GetDirection() const
{
    return direction;
}