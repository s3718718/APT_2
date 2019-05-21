
#include "Tile.h"
#include <iostream>
Tile::Tile(Colour colour, Shape shape)
{
    this->colour = colour;
    this->shape = shape;
}

Tile::Tile()
{
    this->colour = 'Z';
    this->shape = 9;
}

void Tile::printTile()
{
    std::cout<<this->colour<<this->shape<<std::endl;
}

Colour Tile::getColour()
{
    return colour;
}

Shape Tile::getShape()
{
    return shape;
}

void Tile::printColoured(){
    int colorCode=0;
    if(this->colour == RED){
        colorCode=RED_CODE;
    }else if(this->colour == YELLOW){
        colorCode=YELL_CODE;
    }else if(this->colour == ORANGE){
        colorCode=ORAN_CODE;
    }else if(this->colour == GREEN){
        colorCode = GREEN_CODE;
    }else if(this->colour == PURPLE){
        colorCode=PURP_CODE;
    }else if(this->colour == BLUE){
        colorCode = BLUE_CODE;
    }

    std::cout<<ESCAPE<<colorCode<<END_ESCAPE<<this->colour<<this->shape<<RESET;
}