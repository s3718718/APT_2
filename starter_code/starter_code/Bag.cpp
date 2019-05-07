#include <cstdlib>
#include "Bag.h"
#include <iostream>

using std::cout;
using std::endl;
Bag::Bag()
{
    tileList = new LinkedList();
      // add tile of every shape/color combo available
    for ( Colour &color : colours){     //TODo : Fix arrays
        for ( Shape &shape : shapes) {
            Tile tile = Tile(shape, color);
            cout<<"Adding Tile : "<<shape<<color<<std::endl;
            tileList->add(tile);
        }
    }
    tileList->printList();
}

// For debugging purposes. MUST Remove from final impl
void Bag::print()
{
    std::cout << "bagprint";
}

