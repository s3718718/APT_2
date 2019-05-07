#include <cstdlib>
#include "Bag.h"
#include "Tile.h"
#include <iostream>

Bag::Bag()
{
    int tileArr[1];
    tileArr[0] = 1;
    std::cout << tileArr[0] << Tile::colours[0];
    //int iterator = 0;
    // for (const Colour &colour : Tile::colours)
    // {
    //     for (const Shape &shape : Tile::shapes)
    //     {
    //         std::cout << shape << colour;
    //         //may need to allocate to the stack to avoid overwrite
    //         //Tile tile = Tile(colour, shape);
    //         tileArr[iterator] = iterator;

    //         //TODO : add to linkedList, then shuffle
    //     }
    // }
}

// For debugging purposes. MUST Remove from final impl
void Bag::print()
{
    std::cout << "bagprint";
}