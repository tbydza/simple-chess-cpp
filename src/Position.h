#ifndef POSITION_H
#define POSITION_H

#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

/**
  * Class Position.
  * This class represents position as 2 dimensional cartesian coordinates
  * 
  */
class Position
{
public:
  /**
    * Position class constructor.
    * @param x X coordinate.
    * @param y Y coordinate.
    */
  Position(int x, int y);
  /**
    * Position class copy constructor.
    * @param src copied Position.
    */
  Position(const Position &src);
  /**
    * Position class move constructor.
    * @param src copied Position.
    */
  Position(Position &&src);

  /**
    * overloaded = operator
    * @param src other Position.
    */
  Position &operator=(const Position &src);
  /**
    * overloaded + operator
    * @param direction pair of coordinates as offset to current coordinates.
    * @return new Position created by adding offset.
    */
  Position operator+(const pair<int, int> &direction) const;
  /**
    * overloaded == operator
    * @param other other Position.
    * @return true if coordinates are equal or false otherwise
    */
  bool operator==(const Position &other) const;

  ~Position();
  /**
    * Position class constructor.
    * @param column X coordinate in algebric notation.
    * @param row Y coordinate in algebric notation.
    */
  Position(char column, int row);
  /**
    * Position class constructor.
    * @param pos position in algebric notation.
    */
  Position(const string &pos);
  /**
    * Gets X coordinate in algebric notation.
    * @return column character
    */
  char Column() const;
  /**
    * Gets Y coordinate in algebric notation.
    * @return row number.
    */
  int Row() const;
  /**
    * X coordinate getter
    * @return X coordinate
    */
  int GetX() const;
  /**
    * Y coordinate getter
    * @return Y coordinate
    */
  int GetY() const;
  /**
    * Checks if the Position is next to this position 
    * @param pos other Postion
    * @return true if postions are next to each other.
    */
  bool IsNextTo(const Position &pos) const;
  /**
    * Create string containing Position in algebric notation.
    * @return Position in algebric notation.
    */
  string ToString() const;

private:
  int x, y; /**< X and Y coordinates */
  int XFromColumn(char column);

  int YFromRow(int row);
};

#endif