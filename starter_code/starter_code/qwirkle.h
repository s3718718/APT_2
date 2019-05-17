#include <string>
#include <memory>
#include <fstream>
#include "Player.h"
#include "Board.h"

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

private:
  shared_ptr<Bag> bag;
  shared_ptr<Board> board;
  shared_ptr<Player> player1;
  shared_ptr<Player> player2;
  shared_ptr<Player> currentPlayer;
  bool gameOver;
  bool firstTurn;
};

// = std::make_shared<Bag>(null);