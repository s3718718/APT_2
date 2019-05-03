#include <cstdlib>
#include "Player.h"
#include <string>

using std::string;
Player::Player(string name, string studentId, string email){
    this->name = name;
    this->studentId = studentId;
    this->email = email;
    points =0;
}