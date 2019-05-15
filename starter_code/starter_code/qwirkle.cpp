
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
    else if (command = "save")
    {
      //Construct yuge string of the save file
      std::string saveData = "";
      std::string player1Data = "";
      std::string player2Data = "";
      std::string boardData = "";
      std::string bagData = "";

      player1Data.append(player1->getName());
      player1Data.append("\n");
      player1Data.append(std::to_string(player1->getPoints()));
      player1Data.append("\n");
      player1Data.append(player1->hand->toString());

      cout << player1Data << endl;

      player2Data.append(player2->getName());
      player2Data.append("\n");
      player2Data.append(std::to_string(player2->getPoints()));
      player2Data.append("\n");
      player2Data.append(player2->hand->toString());

      cout << player2Data << endl;

      bagData.append(this->bag->toString());

      saveData.append(player1Data);
      saveData.append("\n");
      saveDate.append(player2Data);
      saveData.append("\n");
      saveData.append(boardData);
      saveData.append("\n");
      saveData.append(bagData);
      saveData.append("\n");
      saveData.append(currentPlayer->getName());

      std::ofstream outFile;
      outFile.open(args);
      outFile << saveData << endl;
      outFile.close(args);
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

int qwirkle::checkTiles(Tile tile, int row, int col, Board board, int selection, int direction)
{
  int num = 0;
  bool stop = false;
  int x = row, y = col;
  while (!stop && x > 0 && y > 0 && x < board.getSize() && y < board.getSize())
  {
    if (direction == 1)
      x = x - 1;
    else if (direction == 2)
      x = x + 1;
    else if (direction == 3)
      y = y + 1;
    else if (direction == 4)
      y = y - 1;
    Tile *neighbour = board.getTile(x, y);
    if (neighbour == nullptr)
      stop = true;
    else if (selection == 1 && tile.getColour() == neighbour->getColour())
      num++;
    else if (selection == 2 && tile.getShape() == neighbour->getShape())
      num++;
    else
      stop = true;
  }
  return num;
}

bool qwirkle::placeTile(Tile tile, int row, int col, Board board)
{

  int selection;
  int total = 0;
  if (row < board.getSize() && col < board.getSize())
  {

    // Checking if tile matches the any of four directions one bby one
    for (int d = 1; d <= 4; d++)
    {

      Tile *check = nullptr;
      if (d == 1) // up
        check = board.getTile(row - 1, col);
      else if (d == 2) //down
        check = board.getTile(row + 1, col);
      else if (d == 3) // right
        check = board.getTile(row, col + 1);
      else //left
        check = board.getTile(row, col - 1);

      if (check != nullptr) // if threre is a tile
      {
        // checks if its of same colour or shape
        if (check->getColour() == tile.getColour() || check->getShape() == tile.getShape())
        {
          if (check->getColour() == tile.getColour())
            selection = 1;
          else
            selection = 2;
          // to get number of tiles matching in that direction
          int numOfTiles = 1 + checkTiles(tile, row, col, board, selection, 2);
          if (numOfTiles < 6) // if there are less than 6 in a row, set thde new tile on bboard
          {
            board.setTile(row, col, &tile);
            total = total + 1 + numOfTiles;
          }
        }
      }
    }
  }
  return true;
}
