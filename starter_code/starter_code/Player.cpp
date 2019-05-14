#include <cstdlib>
#include <string>
#include "Player.h"
#include "Tile.h"
#include "Bag.h"
#include "LinkedList.h"


using std::string;
Player::Player(string name)
{
    this->name = name;
    points = 0;
}

string Player::getName()
{
    return name;
}

int Player::getPoints()
{
    return points;
}


void Player::addPoints(int i)
{
    points += i;
}

bool Player::addTile(Tile tile)
{
    //if statement first, return true if pass
    hand->add(tile);
    return true;
}

bool Player::drawTile(Bag bag)
{
    //if statement first, return true if pass
    Tile newTile = bag.takeFirst();
    addTile(newTile);
    return true;
}

Tile Player::removeTile(char colour, int shape)
{
    return hand->takeTile(colour, shape);
}

void Player::fillHand(Bag bag)
{
    int i = 0;
    while (i < HAND_LIMIT)
    {
        drawTile(bag);
    }
}

bool Player::hasTile(char colour, int shape)
{ 
    bool result = false;
    if(hand->get(char colour, int shape) != null)
        result  = true;
    return result;
}

void Player::printHand()
{
    hand->printList();
}

string Player::toString() 
{
    return hand->toString();
}
