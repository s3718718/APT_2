
// Sam Hoch, s3721859
// Labiba islam s3694372
// Md Abir Ishtiaque s3677701
/* Duncan Do s3718718 */
#include "qwirkle.h"
#include <iostream>

#define EXIT_SUCCESS 0

using std::cin;
using std::cout;
using std::endl;

void qwirkle::newGame()
{
  std::string name = "";
  cout << "Starting a New Game" << endl;
  this->bag = std::make_shared<Bag>(*(new Bag()));
  this->bag->print();
  this->board = std::make_shared<Board>(*(new Board(26)));
  cout << "Enter a name for player 1" << endl
       << "> ";
  cin >> name;
  //if (validUserName(name))
  this->player1 = std::make_shared<Player>(*(new Player(name)));
  cout
      << "Enter a name for player 2" << endl
      << "> ";
  cin >> name;
  this->player2 = std::make_shared<Player>(*(new Player(name)));
  //if (validUserName(name))
  cout << "Player 1: " + this->player1->getName() + "\nPlayer 2: " + this->player2->getName() << endl;

  //TODO implement a makeTurn method that handles player actions and keeps repeating until the end
}

void qwirkle::loadGame()
{
  cout << "Please enter save file name (relative path)" << endl;
  cout << "> ";

  std::string fileName;
  std::getline(cin, fileName);

  //TODO
  //loadFile(fileName);
}

void qwirkle::quit()
{
  cout << "Goodbye" << endl;
  exit(0);
}

void qwirkle::loadFile(std::string fileName)
{
  cout << "loading file with filename " << fileName << endl;
}