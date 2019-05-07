
#include "Tile.h"

Tile::Tile(Colour colour,Shape shape){
    this->colour = colour;
    this->shape = shape;
}

void Tile::toString(){
    
}

Colour Tile::getColour(){
    return colour;
}

Shape Tile::getShape(){
    return shape;
}