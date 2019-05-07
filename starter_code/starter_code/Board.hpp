//
//  Board.hpp
//  board
//
//  Created by Labiba Islam on 1/5/19.
//  Copyright © 2019 Labiba Islam. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Tile.h"

class Board
{
public:
    std::vector<std::vector<Tile*>> board; //board is a vector of vectors holding tile pointers. so we can dymanically allocate the tiles and store them in the grid 
    Board();
    Board(int size);
    void display();
};
#endif /* Board_hpp */
