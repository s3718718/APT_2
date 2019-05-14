
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
  Tile();
  void printTile();
  Colour getColour();
  Shape getShape();

private:
  Colour colour;
  Shape shape;
};

#endif // ASSIGN2_TILE_H
