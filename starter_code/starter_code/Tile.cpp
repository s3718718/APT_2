
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