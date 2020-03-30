#ifndef MOVE_H
#define MOVE_H

#include "Position.h"

using namespace std;
/**
 * Move class.
 * This class represents one chess move.
 * Move consist of source and destination Position
 * and its properties.
 */
class Move
{
public:
  /**
  * Move class default constructor.
  * this creates invalid move
  */
  Move();
  /**
  * Move class constructor.
  * @param src source Position of the Move
  * @param dst destination Position of the Move
  * @param capture move with capture of enemy figure.
  * @param castling move is castling special move, default value is false.
  */
  Move(const Position &src, const Position &dst, bool capture, bool castling = false);
  /**
  * Capture property getter
  * @return value of capture property
  */
  bool IsCapture() const;
  /**
  * Castling property getter
  * @return value of castling property
  */
  bool IsCastling() const;
  /**
  * Source Position getter
  * @return source Position.
  */
  Position GetSourcePosition() const;
  /**
  * Destination Position getter
  * @return destination Position.
  */
  Position GetDestinationPosition() const;
  /**
  * overloaded == operator
  * @param other other Move
  * @return true if source and destination positions equal
  */
  bool operator==(const Move &other) const;

private:
  Position src, dst;
  bool castling, capture;
};

#endif