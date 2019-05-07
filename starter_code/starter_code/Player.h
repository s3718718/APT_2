#include "Tile.h"
#include "LinkedList.h"
#include "Bag.h"
#include <string>

#define HAND_LIMIT    6

using std::string;
class Player
{
  public:
    Player(string name, string studentId, string email);
    bool drawTile(Bag bag);   //Removing from bag, adding to hand bag.takeFirst()
    bool addTile(Tile tile);
    bool placeTile(Tile tile);  //Removing from hand, adding to board. NEED to add target location on board (vector of vectors holding tile pointers)
    bool removeTile(Tile tile);
    void addPoints(int i);
    bool hasTile(Tile tile);    //Validate the methods that manipulate tiles
    void fillHand(Bag bag);     // From TileBag
    void printHand();           //For Testing
    bool save(string fileName); //IO

    //Getters
    string getName();
    int getPoints();
    string getStudentId();
    string getEmail();
    
    //Setters
    // void setName(string name);
    // void setPoints(int points);
    // void setStudentId(string studentId);
    // void setEmail(string email);


  private:
    string name;
    string studentId;
    string email;
    int points;
    LinkedList* hand = new LinkedList();
  //TODO : Make ordered linked list of tiles for hand.

};