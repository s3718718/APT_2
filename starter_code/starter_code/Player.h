#include "Tile.h"
#include "Bag.h"
#include "LinkedList.h"

#include <string>

#define HAND_LIMIT 6

using std::string;
class Player
{
public:
  Player(string name);
  //Copy Constructor?
  //Deconstructor?

  //Getters
  string getName();
  int getPoints();

  //Setters
  // void setName(string name);
  // void setPoints(int points);
  // void setStudentId(string studentId);
  // void setEmail(string email);

  void addPoints(int i);
  bool addTile(Tile *tile);
  bool drawTile(Bag bag); //Removing from bag, adding to hand bag.takeFirst()
  Tile *removeTile(char colour, int shape);
  void fillHand(Bag bag);               // From TileBag
  bool hasTile(char colour, int shape); //Validate the methods that manipulate tiles
  void printHand();                     //For Testing //CHANGE TO TOSTRING
  string toString();

private:
  string name;
  int points;
  LinkedList *hand;
};