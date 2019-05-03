
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
   Tile(Colour colour, Shape shape);

  private:
  Colour colour;
  Shape shape;
  Colour colours[6] = {RED,ORANGE,YELLOW,GREEN,BLUE,PURPLE};
  Shape shapes[6] = {CIRCLE,STAR_4,DIAMOND,SQUARE,STAR_6,CLOVER};
};

#endif // ASSIGN2_TILE_H
