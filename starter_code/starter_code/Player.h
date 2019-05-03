#include "Tile.h"
#include <string>

using std::string;
class Player
{
  public:
    Player(string name, string studentId, string email);
    bool placeTile(Tile tile);
    bool removeTile(Tile tile);
    bool save();
    void addPoints(int i);
    int getPoints();
    void fillHand(); // From TileBag


  private:
  string name;
  string studentId;
  string email;
  int points;
  //TODO : Make ordered linked list of tiles for hand.

};