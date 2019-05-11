#include <string>
#include <memory>
#include "Player.h"
#include "Board.hpp"

using std::shared_ptr;

class qwirkle
{
public:
  void newGame();

  void loadGame();

  void quit();

  bool validUserName(std::string name);

  void loadFile(std::string fileName);

  void newTurn();

private:
  shared_ptr<Bag> bag;
  shared_ptr<Board> board;
  shared_ptr<Player> player1;
  shared_ptr<Player> player2;
  shared_ptr<Player> currentPlayer;
  bool gameOver;
};

// = std::make_shared<Bag>(null);