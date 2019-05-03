#include "Tile.h"

class Player
{
  public:
    Player();
    bool placeTile(Tile tile);
    bool removeTile(Tile tile);
    bool save();
};