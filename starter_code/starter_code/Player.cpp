#include <cstdlib>
#include <string>
#include <iostream>
#include "Player.h"

using std::string;

Player::Player(string name)
{
    this->name = name;
    this->hand = new LinkedList();
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

bool Player::addTile(Tile *tile)
{
    //if statement first, return true if pass
    hand->add(tile);
    return true;
}

bool Player::drawTile(Bag bag)
{
    //if statement first, return true if pass
    addTile(bag.pullTile());
    return true;
}

Tile *Player::removeTile(char colour, int shape)
{
    std::cout << "LOL" << std::endl;
    return hand->takeTile(colour, shape);
}

void Player::fillHand(Bag bag)
{
    int i = 0;
    while (i < HAND_LIMIT)
    {
        drawTile(bag);
        i++;
    }
}

bool Player::hasTile(char colour, int shape)
{
    bool result = false;
    if (hand->get(colour, shape) != nullptr)
        result = true;
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
