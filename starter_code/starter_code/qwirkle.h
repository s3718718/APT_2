#include <string>
#include <memory>
#include "Player.h"
#include "Board.h"

using std::shared_ptr;

class qwirkle
{
public:
  void newGame();

  void loadGame();

  void studentInformation();

  void quit();

  bool validUserName(std::string name);

  void loadFile(std::string fileName);

  void newTurn();

  int checkTiles(Tile tile, int row, int col,Board board, int selection, int direction);

  bool placeTile(Tile tile, int row, int col,Board board);

private:
  shared_ptr<Bag> bag;
  shared_ptr<Board> board;
  shared_ptr<Player> player1;
  shared_ptr<Player> player2;
  shared_ptr<Player> currentPlayer;
  bool gameOver;
};

// = std::make_shared<Bag>(null);