#include <cstdlib>
#include "Bag.h"
#include <iostream>

using std::cout;
using std::endl;
Bag::Bag()
{
    tileList = new LinkedList();
    getShuffledBag();
    tileList->printList();
}

// For debugging purposes. MUST Remove from final impl
void Bag::print()
{   
  tileList->printList();
    
}

// Tile Bag::pullTile(){
//     return;
// }

// LinkedList Bag::shuffle(){
//     //TODO
//     return NULL;
// }

bool Bag::isEmpty()
{
    if(tileList->getSize() <= 0){
        return true;
    }
    return false;
}

void Bag::getShuffledBag(){
    // add tile of every shape/color combo available
    for (Colour &color : colours)
    { 
        for (Shape &shape : shapes)
        {
            Tile tile = Tile(color, shape);
            cout << "Adding Tile : " << shape << color << std::endl;
            tileList->add(tile);
        }
    }
    tileList->shuffle();
}