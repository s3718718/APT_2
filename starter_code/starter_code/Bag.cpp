#include <cstdlib>
#include "Bag.h"
#include <iostream>

using std::cout;
using std::endl;
Bag::Bag()
{
    tileList = new LinkedList();
    getShuffledBag();
    //tileList->printList();
}

// For debugging purposes. MUST Remove from final impl
void Bag::print()
{
    tileList->printList();
}

std::string Bag::toString()
{
    return tileList->toString();
}

Tile *Bag::pullTile()
{
    return tileList->takeFirst();
}

void Bag::addTile(Tile *tile)
{
    tileList->add(tile);
}

bool Bag::isEmpty()
{

    return this->tileList->isEmpty();
    // bool retVal = false;
    // if (tileList->getSize() == 0)
    // {
    //     retVal = true;
    // }
    // return retVal;
}

void Bag::getShuffledBag()
{
    // add tile of every shape/color combo available
    for (Colour &color : colours)
    {
        for (Shape &shape : shapes)
        {

            //TODO CHANGE THIS FOR GODS SAKES

            Tile *tile = new Tile(color, shape);
            Tile *tile2 = new Tile(color, shape);
            //  cout << "Adding Tile : " << shape << color << std::endl;
            tileList->add(tile);
            tileList->add(tile2);
        }
    }
    tileList->shuffle();
}