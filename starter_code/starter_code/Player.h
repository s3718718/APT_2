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
    bool hasTile(Tile tile);
    int getPoints();
    void fillHand(); // From TileBag
    void printHand();


  private:
  string name;
  string studentId;
  string email;
  int points;
  //TODO : Make ordered linked list of tiles for hand.

};