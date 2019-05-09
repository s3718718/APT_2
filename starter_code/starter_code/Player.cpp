#include <cstdlib>
#include <string>
#include "Player.h"
#include "Tile.h"

using std::string;
Player::Player(string name)
{
    this->name = name;
    points = 0;
}

bool Player::drawTile(Bag bag)
{
    //if statement first, return true if pass
    // Tile newTile = bag.takeFirst();
    // addTile(newTile);
    return true;
}

bool Player::addTile(Tile tile)
{
    //if statement first, return true if pass
    // hand.add(tile);
    return true;
}

bool Player::placeTile(Tile tile)
{
    //if statement first, return true if pass
    //board.add(tile);
    // hand.remove(tile);
    return true;
}

bool Player::removeTile(Tile tile)
{
    // hand.remove(tile);
    return true;
}
void Player::addPoints(int i)
{
    points += i;
}

bool Player::hasTile(Tile tile)
{
    //TODO
    return true;
}

void Player::fillHand(Bag bag)
{
    int i = 0;
    while (i < HAND_LIMIT)
    {
        drawTile(bag);
    }
}

void Player::printHand()
{
    //TODO
}

bool save(string fileName)
{
    //TODO
    return true;
}

string Player::getName()
{
    return name;
}

int Player::getPoints()
{
    return points;
}
