
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include <string>

class LinkedList
{
public:
  LinkedList();
  ~LinkedList();
  void add(Tile *tile);
  Tile *takeTile(char colour, int shape);
  Tile *get(char colour, int shape);
  Tile *takeFirst();
  void printList();
  void shuffle();
  int getSize();
  void deleteAll();
  std::string toString();
  bool isEmpty();

private:
  Node *head;
  Node *tail;
};

#endif // ASSIGN2_LINKEDLIST_H
