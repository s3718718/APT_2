
// Sam Hoch, s3721859
// Labiba Islam s3694372
// Md Abir Ishtiaque s3677701
// Duncan Do s3718718

//Input format:
//place <tileCode>,<boardPosition>
//replace <tileCode>
#include "qwirkle.h"
#include <iostream>

#define EXIT_SUCCESS 0

using std::cin;
using std::cout;
using std::endl;

void qwirkle::studentInformation()
{
  cout << "Name: Duncan Do\nStudent Number: s3718718\nEmail: s3718718@student.rmit.edu.au" << endl
       << "Name: Sam Hoch\nStudent Number: s3721859\nEmail: s3721859@student.rmit.edu.au" << endl
       << "Name: Labiba Islam\nStudent Number: s3718718\nEmail: s3694372@student.rmit.edu.au" << endl
       << "Name: Md Abir Ishtiaque\nStudent Number: s3718718\nEmail: s3677701@student.rmit.edu.au" << endl;
}

void qwirkle::newGame()
{
  this->gameOver = false;
  std::string name = "";
  cout << "Starting a New Game" << endl;
  this->bag = std::make_shared<Bag>(*(new Bag()));
  cout << this->bag->toString() << endl;
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
  this->currentPlayer = this->player1;
  while (!this->gameOver)
  {
    this->newTurn();
  }
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

/*
Code References for newTurn:
    String splitting using delimiter: 
        https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c 
    
    String to int conversion (stoi):
        https://www.systutorials.com/131/convert-string-to-int-and-reverse/

    String to char conversion (copy):
        https://www.techiedelight.com/convert-string-char-array-cpp/
*/

//TODO
//Runs initially without taking input, then runs again thanks to loop and takes input. Fix this.
void qwirkle::newTurn()
{
  cout << "Player " << this->currentPlayer->getName() << endl;
  cout << this->player1->getName() << ": " << this->player1->getPoints() << ", " << this->player2->getName() << ": " << this->player2->getPoints() << endl;
  this->board->display();
  this->currentPlayer->printHand();
  std::string input;
  bool validInput = false;
  while (!validInput)
  {
    cout << "> ";
    std::getline(cin, input);
    int commandEnd = input.find(' ');
    std::string command = input.substr(0, commandEnd);
    //the 1s depend on delimiter length, hopefully if you need to debug it you find this
    std::string args = input.substr(commandEnd + 1, input.length()); //may need to be length -1

    //TODO
    //maybe wrap in while(validInput) when input is garbo alfonzo
    //lots of magic numbers here, will probs want to fix that at some point. but it works!
    //also change the string initialization to something that isn't trash

    if (command == "place")
    {
      std::string tileString = args.substr(0, args.find(','));
      std::string positionString = args.substr(tileString.length(), args.length());

      char test2 = 'b';

      char *tileCol = &test2;
      tileString.substr(0, 1).copy(tileCol, 1);
      int tileShape = std::stoi(tileString.substr(1, 2));

      char test1 = 'a';
      char *positionChar = &test1;
      positionString.substr(0, 1).copy(positionChar, 0);
      int positionInt = std::stoi(positionString.substr(2, 3));

      cout << "placing " << *tileCol << tileShape << " at " << *positionChar << positionInt << endl;

      validInput = true;
      //Run necessary code to place a tile using *tileCol, tileShape, *positionChar and positionInt
    }
    else if (command == "replace")
    {

      char test3 = 'c';
      char *tileCol = &test3;
      args.substr(0, 1).copy(tileCol, 1);
      int tileShape = std::stoi(args.substr(1, 2));

      cout << "replacing " << *tileCol << tileShape << endl;
      validInput = true;
      //Run necessary code to replace a tile using *tileCol and tileShape

      //this->bag->add(currentPlayer->takeTile());
      //currentPlayer->add(this->bag->takeTile());
    }
    else
    {
      cout << "command \"" << command << "\" unknown" << endl;
    }
  }

  if (this->currentPlayer == this->player1)
  {
    this->currentPlayer = this->player2;
  }
  else if (this->currentPlayer == this->player2)
  {
    this->currentPlayer = this->player1;
  }
  else
  {
    cout << "current player assignment is breaking, debug please" << endl;
  }
}