
// Sam Hoch, s3721859
// Labiba islam s3694372
// Md Abir Ishtiaque s3677701
/* Duncan Do s3718718 */
#include <iostream>
#include "qwirkle.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
  // LinkedList* list = new LinkedList();
  // delete list;

  qwirkle game = qwirkle();

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
    cout << "> ";
    cin >> menuInput;

    if (menuInput == menuInputs[0])
      game.newGame();
    else if (menuInput == menuInputs[1])
      game.loadGame();
    else if (menuInput == menuInputs[2])
    {
      cout << "3 was selected" << endl;
      cout << "--------------" << endl;
      cout << "Name : <full name>" << endl;
      cout << "Student ID <student number>" << endl;
      cout << "Email <email address>" << endl;
    }
    else if (menuInput == menuInputs[3])
      game.quit();
    else
      cout << "Invalid Input" << endl;
  }
  return EXIT_SUCCESS;
}