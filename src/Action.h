#ifndef ACTION_H
#define ACTION_H

#include <memory>

using namespace std;

/**
 * MoveType enum.
 * Represents type of movement of the action shift number of tiles 
 * or do step over to the destination tile.
 */
enum MoveType
{
    shift,
    step,
    doubleStep
};

/**
 * ActionType enum.
 * It represent type of action (move, attack or both).
 */
enum ActionType
{
    moveOnly,
    attackOnly,
    moveOrAttack
};

/**
 * Action class.
 * Action represents possible movement on the chessboard.
 */
class Action
{
  public:
    /**
    * Action class constructor.
    * @param moveType type of movement.
    * @param x x offset.
    * @param y y offset.
    * @param actionType type of action. 
    */
    Action(MoveType moveType, int x, int y, ActionType actionType = moveOrAttack);
    /**
     * Returns direction of the action.
     * @return x and y offset as pair of integers.
     */
    pair<int, int> GetDirection() const;
    /**
     * Returns movement type of the action.
     * @return shift/step/doubleStep
     */
    MoveType GetMoveType() const;
    /**
    * Returns type of action.
    * @return moveOnly/attackOnly/moveOrAttack
    */
    ActionType GetActionType() const;

  private:
    MoveType moveType;
    ActionType actionType;
    pair<int, int> direction; /**< direction of shift move or offset of the step move */
};

#endif