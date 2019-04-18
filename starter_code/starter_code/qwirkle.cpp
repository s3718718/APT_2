
#include "LinkedList.h"

#include <iostream>
// // #include <cstdlib>
#include <ctype.h>
// #include <stdio.h>


#define EXIT_SUCCESS    0

int main(void) {
   // LinkedList* list = new LinkedList();
   // delete list;
   
   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;
   std::cout << "Menu" << std::endl;
   std::cout << "----" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Show student information" << std::endl;
   std::cout << "4. Quit" << std::endl;
   
   std::string menuInputs[4] = {"1", "2", "3", "4"};
   std::string menuInput = "";
   std::cin >> menuInput;

   if(menuInput == menuInputs[0]) {
      std::cout << "Starting a New Game" << std::endl;
      
      std::cout << "Enter a name for player 1" << std::endl;
      // std::string player1Name = "";
      // std::cin >> player1Name;
      // player1Name = toupper(player1Name);
      // std::cout << player1Name << std::endl;
   }
   else if(menuInput == menuInputs[1]) {
      std::cout << "2 was selected" << std::endl;
   }
   else if(menuInput == menuInputs[2]) {
      std::cout << "3 was selected" << std::endl;
   }
   else if(menuInput == menuInputs[3]) {
      std::cout << "4 was selected" << std::endl;
   }

   return EXIT_SUCCESS;
}