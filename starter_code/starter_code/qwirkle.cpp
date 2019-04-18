
#include "LinkedList.h"
#include "QwirkleMenu.h"
#include <iostream>

#define EXIT_SUCCESS    0

using std::cout;
using std::cin;
using std::endl;

int main(void) {
   // LinkedList* list = new LinkedList();
   // delete list;

   std::string menuInputs[4] = {"1", "2", "3", "4"};
   std::string menuInput = "";

   while(menuInput != menuInputs[3]) {
      cout << "Welcome to Qwirkle!" << endl;
      cout << "-------------------" << endl;
      cout << "Menu" << endl;
      cout << "----" << endl;
      cout << "1. New Game" << endl;
      cout << "2. Load Game" << endl;
      cout << "3. Show student information" << endl;
      cout << "4. Quit" << endl;
      
      cin >> menuInput;

      if(menuInput == menuInputs[0]) {
      cout << "Starting a New Game" << endl;      
      cout << "Enter a name for player 1" << endl;
         // cin >> player1Name;
         // player1Name = to_upper(player1Name);
         // cout << player1Name << endl;
      }
      else if(menuInput == menuInputs[1]) {
         cout << "2 was selected" << endl;
         //TODO
      }
      else if(menuInput == menuInputs[2]) {
         cout << "3 was selected" << endl;
         //TODO
      }
      else if(menuInput == menuInputs[3]) {
         cout << "Goodbye" << endl;
         //TODO
      }

      cout << "Invalid Input" << endl;
   }
   return EXIT_SUCCESS;
}