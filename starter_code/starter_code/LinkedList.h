
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList
{
public:
  LinkedList();
  ~LinkedList();
  void add(Tile tile);
  Tile *takeTile(char colour, int shape);
  Tile *get(char colour, int shape);
  Tile *takeFirst();
  void printList();
  Tile* toArray();
  int getSize();
  void deleteAll();

private:
  Node *head;
  Node *tail;
};

#endif // ASSIGN2_LINKEDLIST_H
