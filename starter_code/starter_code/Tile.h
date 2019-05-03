
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H
#include "TileCodes.h"
// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile
{
 public:
  static constexpr Colour colours[6] = {RED,ORANGE,YELLOW,GREEN,BLUE,PURPLE};
  static constexpr Shape shapes[6] = {CIRCLE,STAR_4,DIAMOND,SQUARE,STAR_6,CLOVER};
  Tile(Colour colour, Shape shape);
  void toString();

 private:
  Colour colour;
  Shape shape;
};

#endif // ASSIGN2_TILE_H
