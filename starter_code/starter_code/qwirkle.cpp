
// Sam Hoch, s3721859
// Labiba Islam s3694372
// Md Abir Ishtiaque s3677701
// Duncan Do s3718718

//Input format:
//place <tileCode>,<boardPosition>
//replace <tileCode>
#include "qwirkle.h"
#include <iostream>
#include <cctype>
#include <stdexcept>

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
  this->firstTurn = true;
  this->gameOver = false;
  std::string name = "";
  int numPlayers;
  cout << "Starting a New Game" << endl;
  //TODO : Do check for min 2 players.
  //bool check = true;
  //do{
  cout << "How many players?" <<endl;
  cin >> numPlayers;
  //}while(check);
  this->bag = std::make_shared<Bag>(*(new Bag()));
  cout << this->bag->toString() << endl;
  this->board = std::make_shared<Board>(*(new Board(26)));
  cout << "Enter a name for player 1" << endl
       << "> ";
  cin >> name;
  //if (validUserName(name))
  this->player1 = std::make_shared<Player>(*(new Player(name)));
  this->player1->fillHand(*this->bag);
  cout
      << "Enter a name for player 2" << endl
      << "> ";
  cin >> name;
  this->player2 = std::make_shared<Player>(*(new Player(name)));
  this->player2->fillHand(*this->bag);
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
      try{
      std::string tileString = args.substr(0, args.find(','));
      std::string positionString = args.substr(tileString.length(), args.length());

      char test2 = 'b';

      char *tileCol = &test2;
      tileString.substr(0, 1).copy(tileCol, 1);
      int tileShape = std::stoi(tileString.substr(1, 2));

      char test1 = 'a';
      char *positionChar = &test1;
      positionString.substr(1, 2).copy(positionChar, 1);
      int positionInt = std::stoi(positionString.substr(2, 3));
      int positionCharInt = this->getIntFromChar(*positionChar);

      validInput = true;
      //Run necessary code to place a tile using *tileCol, tileShape, *positionChar and positionInt
      
      this->placeTile(this->currentPlayer->removeTile(*tileCol, tileShape), positionCharInt, positionInt, this->firstTurn);
      }catch(const std::invalid_argument& e){
        cout<<"Invalid arguments!"<< e.what() <<endl;
      }
      //cout << "after placeTile in newTurn, using this->board->getTile() col = " << this->board->getTile(5, 5)->getColour() << endl;
      this->firstTurn = false;
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

    else if (command == "save")
    {
      this->saveGame(args);
    }
    else if(command == "help")
    {
      cout<<" --------List of valid commands------------"<<endl;
      cout<<"place <tileCode>,<boardPosition> to place a tile in the board"<<endl;
      cout<<"replace <tileCode> to replace a tile from your hand"<<endl;
      cout<<"save <filename> to save game"<<endl;
      cout<<"^D to quit game"<<endl;
    }

    else
    {
      cout << "command \"" << command << "\" unknown" << endl;
      validInput = false;
    }
  } // end of while

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

// bool qwirkle::validateMove(char colour, int shape, int row, int col) {
//   bool valid = false;
//   Tile neighbours[4] = {
//     board->getTile(row - 1, col), 
//     board->getTile(row, col + 1), 
//     board->getTile(row + 1, col), 
//     board->getTile(row, col - 1)
//     };

//   for(int i = 0; i < neighbours.size(); i++) {
//     if(neighbours[i] != nullptr) {
//       if((neighbours[i]->getColour() == colour) && (neighbours[i]->getShape() == shape) {
//         int x = 0;
//         int y = 0;
//         if(i = 0) {
//           x = row - 2;
//           y = col;
//         }
//         else if(i = 1) {
//           x = row;
//           y = col + 2;
//         }
//         else if(i = 2) {
//           x = row + 2;
//           y = col;
//         }
//         else if(1 = 3) {
//           x = row;
//           y = col - 2;
//         }
//         if(neighbours[i]s position + 1 != nullptr) {
//            if(board->getTile(x,y)->getColour() == colour) && (board->getTile(x,y)->getShape() == shape) {
//              valid = true;
//            }
//         }
//       }
//     }
//   }
//   return valid;
// }

int qwirkle::checkTiles(Tile *tile, int row, int col, int selection, int direction)
{
  int num = 0;
  bool stop = false;
  int x = row, y = col;
  while (!stop && x > 0 && y > 0 && x < this->board->getSize() && y < this->board->getSize())
  {
    if (direction == 1)
      x = x - 1;
    else if (direction == 2)
      x = x + 1;
    else if (direction == 3)
      y = y + 1;
    else if (direction == 4)
      y = y - 1;
    Tile *neighbour = this->board->getTile(x, y);
    if (neighbour == nullptr)
      stop = true;
    else if (selection == 1 && tile->getColour() == neighbour->getColour())
      num++;
    else if (selection == 2 && tile->getShape() == neighbour->getShape())
      num++;
    else
      stop = true;
  }
  return num;
}

bool qwirkle::placeTile(Tile *tile, int row, int col, bool firstTurn)
{

  int selection;
  int total = 0;

  if (row < this->board->getSize() && col < this->board->getSize())
  {
    if (firstTurn)
    {
      this->board->setTile(row, col, tile);
      total = total + 1;
      this->currentPlayer->addPoints(total);
    }
    else
    {
      // Checking if tile matches the any of four directions one bby one
      for (int d = 1; d <= 4; d++)
      {

        Tile *check = nullptr;
        if (d == 1) // up
          check = this->board->getTile(row - 1, col);
        else if (d == 2) //down
          check = this->board->getTile(row + 1, col);
        else if (d == 3) // right
          check = this->board->getTile(row, col + 1);
        else //left
          check = this->board->getTile(row, col - 1);

        cout << "b4 test 2" << endl;
        if (check != nullptr) // if threre is a tile
        {
          cout << "plassing test 2" << endl;

          // checks if its of same colour or shape
          if (check->getColour() == tile->getColour() || check->getShape() == tile->getShape())
          {
            cout << "plassing test 3" << endl;
            if (check->getColour() == tile->getColour())
              selection = 1;
            else
              selection = 2;
            // to get number of tiles matching in that direction
            int numOfTiles = 1 + checkTiles(tile, row, col, selection, 2);
            if (numOfTiles < 6) // if there are less than 6 in a row, set thde new tile on bthis->board
            {
              if (this->board->getTile(row, col) == nullptr) //if the selected location is empty
              {
                this->board->setTile(row, col, tile);
                std::cout << "from placeTile, using this->board->getTile colour is: " << this->board->getTile(row, col)->getColour() << endl;
                total = total + 1 + numOfTiles;
                this->currentPlayer->addPoints(total);
              }
            }
          }
        }
      }
    }
  }
  return true;
}

void qwirkle::saveGame(std::string saveFile)
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
  player1Data.append(player1->toString());

  cout << player1Data << endl;

  player2Data.append(player2->getName());
  player2Data.append("\n");
  player2Data.append(std::to_string(player2->getPoints()));
  player2Data.append("\n");
  player2Data.append(player2->toString());

  cout << player2Data << endl;

  bagData.append(this->bag->toString());
  boardData.append(this->board->toString());

  saveData.append(player1Data);
  saveData.append("\n");
  saveData.append(player2Data);
  saveData.append("\n");
  saveData.append(boardData);
  saveData.append("\n");
  saveData.append(bagData);
  saveData.append("\n");
  saveData.append(currentPlayer->getName());

  std::ofstream outFile;
  outFile.open(saveFile);
  outFile << saveData << endl;
  outFile.close();
}

int qwirkle::getIntFromChar(char c)
{
  c = std::toupper(c);
  cout << "input = " << c << endl;
  int output;
  if (c == 'A')
    output = 0;
  else if (c == 'B')
    output = 1;
  else if (c == 'C')
    output = 2;
  else if (c == 'D')
    output = 3;
  else if (c == 'E')
    output = 4;
  else if (c == 'F')
    output = 5;
  else if (c == 'G')
    output = 6;
  else if (c == 'H')
    output = 7;
  else if (c == 'I')
    output = 8;
  else if (c == 'J')
    output = 9;
  else if (c == 'K')
    output = 10;
  else if (c == 'L')
    output = 11;
  else if (c == 'M')
    output = 12;
  else if (c == 'N')
    output = 13;
  else if (c == 'O')
    output = 14;
  else if (c == 'P')
    output = 15;
  else if (c == 'Q')
    output = 16;
  else if (c == 'R')
    output = 17;
  else if (c == 'S')
    output = 18;
  else if (c == 'T')
    output = 19;
  else if (c == 'U')
    output = 20;
  else if (c == 'V')
    output = 21;
  else if (c == 'W')
    output = 22;
  else if (c == 'X')
    output = 23;
  else if (c == 'Y')
    output = 24;
  else if (c == 'Z')
    output = 25;
  else
    output = 26;

  return output;
}
