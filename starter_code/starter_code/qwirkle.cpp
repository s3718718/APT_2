
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

void QwirkleMenu::newGame() {
   std::string inputName = "";
   cout << "Starting a New Game" << endl;
   
   cout << "Enter a name for player 1" << endl;
   cin >> name;
   if(validUserName(name))
      player1Name = name;

   cout << "Enter a name for player 2" << endl;
   cin >> name;
   if(validUserName(name))
      player2Name = name;
   
   cout << "Player 1: " + player1Name + "\nPlayer 2: " + player2Name <<endl;
}

void QwirkleMenu::loadGame() {
   cout << "2 was selected" << endl;
}

void QwirkleMenu::studentInfo() {
   cout << "3 was selected" << endl;
}

void QwirkleMenu::quit() {
   cout << "Goodbye" << endl;
   exit(0);
}

bool QwirkeMenu::validUserName(std::string name) {
   return true;
}