//
//  Board.cpp
//  board
//
//  Created by Labiba Islam on 1/5/19.
//  Copyright © 2019 Labiba Islam. All rights reserved.
//

#include "Board.hpp"
//to make an empty grid of size nxn. it has initially all nullpointers which can be later replaced with pointer to tiles
Board::Board(int size)
{
    for(int i=0;i<size;i++)
    {
        std::vector<Tile*> row;
        for(int j=0;j<size;j++)
        {
            row.push_back(nullptr);
        }
        board.push_back(row);
    }
}
Board::Board()
{
    std::vector<Tile*> row1;
    row1.push_back(nullptr);
    row1.push_back(nullptr);
    row1.push_back(nullptr);
    row1.push_back(nullptr);
    row1.push_back(nullptr);
    row1.push_back(nullptr);
    board.push_back(row1);
    
    std::vector<Tile*> row2;
    row2.push_back(nullptr);
    row2.push_back(nullptr);
    row2.push_back(new Tile('B',4));
    row2.push_back(new Tile('B',5));
    row2.push_back(new Tile('B',6));
    row2.push_back(nullptr);
    board.push_back(row2);
    
    std::vector<Tile*> row3;
    row3.push_back(nullptr);
    row3.push_back(nullptr);
    row3.push_back(new Tile('R',4));
    row3.push_back(nullptr);
    row3.push_back(nullptr);
    row3.push_back(nullptr);
    board.push_back(row3);
    
    std::vector<Tile*> row4;
    row4.push_back(nullptr);
    row4.push_back(new Tile('Y',1));
    row4.push_back(new Tile('Y',4));
    row4.push_back(new Tile('Y',2));
    row4.push_back(nullptr);
    row4.push_back(nullptr);
    board.push_back(row4);
    
    std::vector<Tile*> row5;
    row5.push_back(nullptr);
    row5.push_back(nullptr);
    row5.push_back(new Tile('P',4));
    row5.push_back(nullptr);
    row5.push_back(nullptr);
    row5.push_back(nullptr);
    board.push_back(row5);
    
    std::vector<Tile*> row6;
    row6.push_back(nullptr);
    row6.push_back(nullptr);
    row6.push_back(nullptr);
    row6.push_back(nullptr);
    row6.push_back(nullptr);
    row6.push_back(nullptr);
    board.push_back(row6);
    
    
}
//this is to display the grid
void Board::display()
{
    int n=(int)board.size();
    std::cout<<"   ";
   // shows the top most row conatining integers b0 , 1 2 and so on
    for(int k=0; k<n; k++)
        std::cout<<k<<"  ";
    std::cout<<"\n  ";
    for(int t=0; t<n; t++)
        std::cout<<"---";
    std::cout<<std::endl;
    // loops to print the vector of vectors
    for(int i=0;i<n;i++)
    {
        std::cout<<(char)('A'+i)<<" |";
        for(int j=0;j<n;j++)
        {
            if(board[i][j] != nullptr)
                std::cout<<board[i][j]->colour<<board[i][j]->shape<<"|";
            else
                std::cout<<"  |";
        }
        std::cout<<std::endl;
    }
}
