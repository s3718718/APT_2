
// Sam Hoch, s3721859
// Labiba islam s3694372
// Md Abir Ishtiaque s3677701
/* Duncan Do s3718718 */
#include "LinkedList.h"
#include "QwirkleMenu.h"
#include <iostream>

#define EXIT_SUCCESS 0

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
  // LinkedList* list = new LinkedList();
  // delete list;

  std::string menuInputs[4] = {"1", "2", "3", "4"};
  std::string menuInput = "";

  while (menuInput != menuInputs[3])
  {
    cout << "Welcome to Qwirkle!" << endl;
    cout << "-------------------" << endl;
    cout << "Menu" << endl;
    cout << "----" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Show student information" << endl;
    cout << "4. Quit" << endl;

    cin >> menuInput;

    if (menuInput == menuInputs[0])
      newGame();
    else if (menuInput == menuInputs[1])
      loadGame();
    else if (menuInput == menuInputs[2])
      studentInfo();
    else if (menuInput == menuInputs[3])
      quit();
    else
      cout << "Invalid Input" << endl;
  }
  return EXIT_SUCCESS;
}

public void QuirkleMenu::newGame() {
   cout << "Starting a New Game" << endl;
   cout << "Enter a name for player 1" << endl;
   cin >> player1Name;
   // validUserName(player1Name);
   // player1Name = to_upper(player1Name);
   // cout << player1Name << endl;
}

public void QuirkleMenu::loadGame() {
   cout << "2 was selected" << endl;
}

public void QuirkleMenu::studentInfo() {
   cout << "3 was selected" << endl;
}

public void QuirkleMenu::quit() {
   cout << "Goodbye" << endl;
   exit(0);
}