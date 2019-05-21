
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
  numPlayers=0;
  cout << "Starting a New Game" << endl;
  
    while(numPlayers<2 || numPlayers >4)
    {
  cout << "How many players?" << endl;
  cin >> numPlayers;
    }
  this->bag = std::make_shared<Bag>(*(new Bag()));
  //cout << this->bag->toString() << endl;
  this->board = std::make_shared<Board>(*(new Board(6)));

  for(int i=0;i<numPlayers;i++)
  {
    //bool valid = false;
    std::string name = "invalid";

    // while(!valid)
    // {
      cout << "Enter a name for player (Only uppercase characters)"<<i+1<< endl
      << "> ";
      cin >> name;
      if(validUserName(name))
      {
        this->players[i] = std::make_shared<Player>(*(new Player(name)));
        this->players[i]->fillHand(*this->bag);
        //valid = true;
      }
      else
      {
        cout << "Invalid username, please only enter uppercase characters" << endl;
      }
   // }
  }
  cout<<"Players for the game are \n";
  for(int i=0;i< numPlayers; i++)
  cout << "Player "<<i+1<<" : " + this->players[i]->getName() + "\n";

  turn = 0;
 // this->currentPlayer = this->players[0];
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
  cin.ignore();
  std::getline(cin, fileName);

  std::string saveData = "";

  cout << "filename = " << fileName << endl;
  std::ifstream inFile;
  inFile.open(fileName);
  while (!inFile.eof())
  {
    std::string temp = "";
    std::getline(inFile, temp);
    saveData.append(temp);
    saveData.append("\n");
  }
  inFile.close();

  int boardStart = saveData.find("  |");
  std::string playerData = saveData.substr(0, boardStart);
  int boardEnd = saveData.substr(boardStart, saveData.length()).find("$");
  std::string boardData = saveData.substr(boardStart, boardEnd);
  std::string finalData = saveData.substr(playerData.length() + boardEnd, saveData.length());
  int bagEnd = finalData.find("\n");
  std::string bagData = finalData.substr(1, bagEnd);
  std::string currentPlayerName = finalData.substr(bagEnd + 1, finalData.length());

  std::vector<std::string> bagString = splitString(bagData, ", ");
  std::vector<std::string> playersDataString = splitString(playerData, "$\n");
  std::vector<std::string> boardString = splitString(boardData, "|");

  cout << "after loop" << endl;
  //bag
  std::vector<Tile *> bagContents = getTileVectorFromStringVector(bagString);

  //nest in for loop
  std::vector<Player *> players = getPlayerVectorFromStringVector(playersDataString);

  //                initialization
  //board
  this->setBoardState(boardString);

  //bag
  this->bag = std::make_shared<Bag>(*(new Bag()));
  for (unsigned int i = 0; i < bagContents.size(); ++i)
  {
    this->bag->addTile(bagContents[i]);
  }
 /* this->player1 = std::make_shared<Player>(*(new Player("yikes1")));
  this->player2 = std::make_shared<Player>(*(new Player("yikes2")));
  this->currentPlayer = player1;
*/
// To read the player details from the vector of players created above
  while (!gameOver)
  {
    this->newTurn();
  }
  cout << "done?" << endl;
  /*TODO
    
    addPlayersFromVector
      takes string of multiple players data, adds each player to the game
    initalizeBoardFromString
      takes string of new board state, intializes new board, then sets the tile strings 
      it finds to the correct position.
      Can use double-to-int casting and modulous to automatically set correct board location
      (col = listPosition mod 26, row = (int) listPosition / 26)


*/
  //loadFile(fileName);
}
/*
Looping logic referenced: 
  https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
  */

void qwirkle::setBoardState(std::vector<std::string> input)
{
  this->board = std::make_shared<Board>(*(new Board(26)));
  for (unsigned int i = 0; i < input.size(); ++i)
  {
    if (input[i] != "  " && input[i] != "\n  " && input[i] != "\n")
    {

      Tile *tile = makeTileFromString(input[i]);
      //Tile *tileTest = new Tile('P', 3);
      int row = i / 26;
      int col = i % 26;
      //cout << i << " " << row << " " << col << endl;
      this->board->setTile(row, col, tile);
      //cout << "COL FROM BOARD POSITION " << row << ", " << col << "= " << this->board->getTile(row, col)->getColour() << endl;
    }
  }
}

std::vector<std::string> qwirkle::splitString(std::string input, std::string delim)
{
  std::vector<std::string> output;
  unsigned int position = 0;
  // std::string end = "\n";
  //cout << "<<" << input << ">>" << endl;
  std::string datum = "";
  bool endOfInput = false;
  while ((position = input.find(delim)) != std::string::npos && !endOfInput)
  {
    if (input != "")
    {
      datum = input.substr(0, position);
      //cout << tile << endl;
      output.push_back(datum);
      input.erase(0, position + delim.length());
    }
    else
    {
      endOfInput = true;
    }
  }
  return output;
}

std::vector<Tile *> qwirkle::getTileVectorFromStringVector(std::vector<std::string> input)
{
  std::vector<Tile *> output;
  for (std::string tileString : input)
  {
    output.push_back(makeTileFromString(tileString));
  }
  return output;
}

std::vector<Player *> qwirkle::getPlayerVectorFromStringVector(std::vector<std::string> input)
{
  //cout << "getPlayerVectorFromStringVector running" << endl;
  std::vector<Player *> output;
  for (unsigned int i = 0; i < input.size(); ++i)
  {
    //cout << "playerString = " << input[i] << endl;
    output.push_back(makePlayerFromString(input[i]));
  }
  return output;
}

/*
  std::vector<Tile *> qwirkle::getTileVectorFromString(std::string input, std::string delim)
  {
    std::vector<Tile *> output;
    unsigned int position = 0;
    // std::string end = "\n";
    cout << "<<" << input << ">>" << endl;
    std::string tile = "";
    bool endOfInput = false;
    while ((position = input.find(delim)) != std::string::npos && !endOfInput)
    {
      if (input != "")
      {
        tile = input.substr(0, position);
        //cout << tile << endl;
        output.push_back(makeTileFromString(tile));
        input.erase(0, position + delim.length());
      }
      else
      {
        endOfInput = true;
      }
      // else
      // {
      //   keepLooping = false;
      // }
    }
    return output;
  }
*/
Tile *qwirkle::makeTileFromString(std::string input)
{
  char c = 'a';
  char *tileCol = &c;
  //cout << "reading before tileString" << endl;
  input.substr(0, 1).copy(tileCol, 1);
  //cout << "reading before tileShape" << endl;
  int tileShape = std::stoi(input.substr(1, input.length()));
  //cout << "reading after tileShape" << endl;
  Tile *tile = new Tile(*tileCol, tileShape);

  return tile;
}

Player *qwirkle::makePlayerFromString(std::string input)
{
  std::vector<std::string> playerData = splitString(input, "\n");
  //cout << "supposedly player name = " << playerData[0] << endl;
  Player *player = new Player(playerData[0]);
  player->setPoints(std::stoi(playerData[1]));
  std::vector<Tile *> hand = getTileVectorFromStringVector(splitString(playerData[2], ", "));
  for (unsigned int i = 0; i < hand.size(); i++)
  {
    player->addTile(hand[i]);
  }

  return player;
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
int qwirkle::getCurrentPlayerIndexByName(std::string name)
{
  int output = 0;
  for (unsigned int i = 0; i < this->players.size(); ++i)
  {
    if (this->players[i]->getName() == name)
    {
      output = (int)i;
    }
  }
  return output;
}
*/

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
  cout<<"Starting new game \n";
  cout << "Player " << this->players[turn]->getName() << "\'s turn "<<endl;
  for(int i=0;i<numPlayers; i++)
  cout << this->players[i]->getName() << ": " << this->players[i]->getPoints() << "\n ";
  this->board->display();
  cout << "Your hand is" << endl;
  this->players[turn]->printHand();
  std::string input;
  bool validInput = false;
  while (!validInput)
  {
    cout << "> ";
    if (this->firstTurn)
      cin.ignore();
    std::getline(cin, input);
    int commandEnd = input.find(' ');
    std::string command = input.substr(0, commandEnd);
    //the 1s depend on delimiter length, hopefully if you need to debug it you find this
    std::string args = input.substr(commandEnd + 1, input.length()); //may need to be length -1

    if (command == "place")
    {
      try
      {
        if(args.length() <8 || args.length()>9)
        {
          cout<<"Invalid command format, enter 'help' for list of valid commands";
        }
        else
        {
      std::string tileString = args.substr(0,2);
      std::string positionString = args.substr(6);
      Colour tileCol = tileString[0];
      Shape tileShape = std::stoi(tileString.substr(1));
      int placeRow = getIntFromChar(positionString[0]);
      int placeCol = std::stoi(positionString.substr(1));
      cout<<tileCol<<tileShape<<placeRow<<placeCol<<"\n";
    
      validInput = true;
      //Run necessary code to place a tile using *tileCol, tileShape, *positionChar and positionInt
      
      this->placeTile(this->players[turn]->removeTile(tileCol, tileShape), placeRow, placeCol, this->firstTurn);
      this->players[turn]->drawTile(*(this->bag));
      
        }
      }catch(const std::invalid_argument& e){
        cout<<"Invalid arguments! To place a tile you must enter 'place <tile> at <grid location>'" <<endl;
      }catch(const std::out_of_range& e){
        cout<<"Out of range!"<<endl;
      }
      //cout << "after placeTile in newTurn, using this->board->getTile() col = " << this->board->getTile(5, 5)->getColour() << endl;
      this->firstTurn = false;
      validInput = true;
    }
    else if (command == "replace")
    {
      try{
      char test3 = 'c';
      char *tileCol = &test3;
      args.substr(0, 1).copy(tileCol, 1);
      Shape tileShape = std::stoi(args.substr(1, 2));

      cout << "replacing " << *tileCol << tileShape << endl;
      this->bag->addTile(this->players[turn]->removeTile(*tileCol,tileShape));
      this->players[turn]->drawTile(*(this->bag));
      validInput = true;
      }catch(const std::invalid_argument& e){
      cout<<"Invalid arguments! To place a tile you must enter 'replace <tile>'";
      }
      //Run necessary code to replace a tile using *tileCol and tileShape

      //this->bag->add(currentPlayer->takeTile());
      //currentPlayer->add(this->bag->takeTile());
    }

    else if (command == "save")
    {
      this->saveGame(args);
    }
    else if (command == "help")
    {
      cout << " --------List of valid commands------------" << endl;
      cout << "place <tileCode> at <boardPosition> to place a tile in the board" << endl;
      cout << "replace <tileCode> to replace a tile from your hand" << endl;
      cout << "save <filename> to save game" << endl;
      cout << "^D to quit game" << endl;
    }

    else
    {
      cout << "command \"" << command << "\" unknown. Type 'help' to see list of availabe commands." << endl;
      validInput = false;
    }
  } // end of while


  turn++;
  turn = turn %numPlayers;
}


int qwirkle::checkTiles(Tile *tile, int row, int col, int selection, int direction)
{
  int num = 0;
  bool stop = false;
  int x = row, y = col;
  while (!stop && x > 0 && y > 0 && x < this->board->getSize() && y < this->board->getSize())
  {
    if (direction == UP)
      x = x - 1;
    else if (direction == DOWN)
      x = x + 1;
    else if (direction == RIGHT)
      y = y + 1;
    else if (direction == LEFT)
      y = y - 1;
    Tile *neighbour = this->board->getTile(x, y);
    if (neighbour == nullptr)
      stop = true;
    else if (selection == MATCH_COLOUR && tile->getColour() == neighbour->getColour())
      num++;
    else if (selection == MATCH_SHAPE && tile->getShape() == neighbour->getShape())
      num++;
    else
      stop = true;
  }
  return num;
}

bool qwirkle::placeTile(Tile *tile, int row, int col, bool firstTurn)
{
  cout << "placeTile starting" << endl;
  int selection;
  int total = 0;

  if (row < this->board->getSize() && col < this->board->getSize())
  {
    cout << "Entered if " << endl;
    if(row == this->board->getSize()-1 || col == this->board->getSize()-1){
      cout<<"Board resiezd"<<endl;
      this->board->reSize();
    }
    if(row>=0 && row < this->board->getSize() && col>=0 && col < this->board->getSize()){
    if (firstTurn)
    {
      this->board->setTile(row, col, tile);
      total = total + 1;
      this->players[turn]->setPoints(total);
    }
    else
    {
      // Checking if tile matches the any of four directions one bby one
      for (int d = 1; d <= 4; d++)
      {

        Tile *check = nullptr;
        if (d == UP && row-1>=0) 
          check = this->board->getTile(row - 1, col);
        else if (d == DOWN && row + 1 < this->board->getSize()) //down
          check = this->board->getTile(row + 1, col);
        else if (d == RIGHT && col+1 < this->board->getSize()) // right
          check = this->board->getTile(row, col + 1);
        else if(d==LEFT && col - 1 >= 0) //left
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
              selection = MATCH_COLOUR;
            else
              selection = MATCH_SHAPE;
            // to get number of tiles matching in that direction
            int numOfTiles = 1 + checkTiles(tile, row, col, selection, d);
            if (numOfTiles < 6) // if there are less than 6 in a row, set thde new tile on bthis->board
            {
              if (this->board->getTile(row, col) == nullptr) //if the selected location is empty
              {
                this->board->setTile(row, col, tile);
                std::cout << "from placeTile, using this->board->getTile colour is: " << this->board->getTile(row, col)->getColour() << endl;
                total =  1 + numOfTiles;
                this->players[turn]->setPoints(total);
              }
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
  //std::string player2Data = "";
  std::string boardData = "";
  std::string bagData = "";

  //TODO change player data to a for loop for the players array
  for(int i=0;i<numPlayers;i++)
  {
     player1Data.append(players[i]->getName());
      player1Data.append("\n");
      player1Data.append(std::to_string(players[i]->getPoints()));
  player1Data.append("\n");
  player1Data.append(players[i]->toString());
  player1Data.append("$");

  cout << player1Data << endl;
saveData.append(player1Data);
  saveData.append("\n");
  player1Data ="";
  
  }
  /*
  player1Data.append(player1->getName());
  player1Data.append("\n");
  player1Data.append(std::to_string(player1->getPoints()));
  player1Data.append("\n");
  player1Data.append(player1->toString());
  player1Data.append("$");

  cout << player1Data << endl;

  player2Data.append(player2->getName());
  player2Data.append("\n");
  player2Data.append(std::to_string(player2->getPoints()));
  player2Data.append("\n");
  player2Data.append(player2->toString());
  player2Data.append("$");

  cout << player2Data << endl;
*/
  bagData.append(this->bag->toString());
  boardData.append(this->board->toString());
  boardData.append("$");
/*
  saveData.append(player1Data);
  saveData.append("\n");
  saveData.append(player2Data);
  saveData.append("\n");*/
  saveData.append(boardData);
  saveData.append("\n");
  saveData.append(bagData);
  saveData.append("\n");
  saveData.append(this->players[turn]->getName());

  std::ofstream outFile;
  outFile.open(saveFile);
  outFile << saveData << endl;
  outFile.close();
}

/*
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

*/

int qwirkle::getIntFromChar(char c){
  int retVal = 0;
  if(isalpha(c)){
    retVal = c-'A';
  }else{
    retVal = -1;
  }
  return retVal;
}

bool qwirkle::validUserName(std::string name) 
{
  bool valid = true;
  for(char& c : name)
  {
    if(!isalpha(c))
    {
      valid = false;
    }
    if(c <= 'A' && c >= 'Z')
    {
      valid = false;
    }
  }
  return valid;
}