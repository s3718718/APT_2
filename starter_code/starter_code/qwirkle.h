#include <string>
#include <memory>
#include <fstream>
#include "Player.h"
#include "Board.h"

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

#define MATCH_COLOUR 1
#define MATCH_SHAPE 2

#define MAX_PLAYERS 4
using std::shared_ptr;

class qwirkle
{
public:
  void newGame();

  void saveGame(std::string saveFile);

  void loadGame();

  void studentInformation();

  void quit();

  bool validUserName(std::string name);

  void loadFile(std::string fileName);

  void newTurn();

  bool validateMove(char colour, int shape, int row, int col);

  int checkTiles(Tile *tile, int row, int col, int selection, int direction);

  bool placeTile(Tile *tile, int row, int col, bool firstTurn);

  int getIntFromChar(char c);

  Tile *makeTileFromString(std::string input);

  Player *makePlayerFromString(std::string input);

  std::vector<std::string> splitString(std::string input, std::string delim);

  std::vector<Tile *> getTileVectorFromStringVector(std::vector<std::string> input);

  std::vector<Player *> getPlayerVectorFromStringVector(std::vector<std::string> input);

  void setBoardState(std::vector<std::string> input);

  //int getCurrentPlayerIndexByName(std::string name);

private:
  shared_ptr<Bag> bag;
  shared_ptr<Board> board;
 // shared_ptr<Player> player1;
  //shared_ptr<Player> player2;
  shared_ptr<Player> players[MAX_PLAYERS];
 // shared_ptr<Player> currentPlayer;
  bool gameOver;
  bool firstTurn;
  int numPlayers;
  int turn;
};