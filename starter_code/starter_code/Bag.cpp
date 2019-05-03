#include <cstdlib>
#include "Bag.h"
#include "Tile.h"

Bag::Bag(){
    for(const Colour &colour : Tile::colours){
        for(const Shape &shape : Tile::shapes){
            Tile tile = Tile(colour,shape);
            //TODO : add to linkedList, then shuffle
        }
    }
}

// For debugging purposes. MUST Remove from final impl
void Bag::print(){

}