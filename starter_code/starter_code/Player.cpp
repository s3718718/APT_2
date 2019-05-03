#include <cstdlib>
#include "Player.h"
#include <string>
#include "Tile.h"

using std::string;
Player::Player(string name, string studentId, string email){
    this->name = name;
    this->studentId = studentId;
    this->email = email;
    points =0;
}

void Player::addPoints(int i){
    points += i;
}

int Player::getPoints(){
    return points;
}

bool Player::hasTile(Tile tile){
    //TODO
}

bool Player::removeTile(Tile tile){
    //TODO
}

void Player::fillHand(){
    //TODO
}