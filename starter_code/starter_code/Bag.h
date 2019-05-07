#include <cstdlib>
#include "Tile.h"
#include "LinkedList.h"
class Bag
{
public:
    Colour colours[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    Shape shapes[6] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};
  Bag();
  int size();
  Tile pullTile();
  void print();
  LinkedList shuffle();
  bool isEmpty();

private:
  LinkedList* tileList;
};