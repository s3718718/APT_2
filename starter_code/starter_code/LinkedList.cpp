
#include "LinkedList.h"
#include <iostream>

//TODO: Rewrite code to comply with structured programming

LinkedList::LinkedList()
{
  head = nullptr;
  tail = nullptr;
}

LinkedList::~LinkedList()
{
}

void LinkedList::printList()
{
  Node *currentNode = head;
  // Tile *output == nullptr;
  std::cout << "---LinkedList Contents---" << std::endl;
  while (currentNode != nullptr)
  {
    //check if current node matches args, if it don't currentNode = currentNode.getNext()
    int tileShape = currentNode->getValue()->getShape();
    char tileCol = currentNode->getValue()->getColour();
    std::cout << tileCol << tileShape << std::endl;
    currentNode = currentNode->getNext();
  }
  std::cout << "---End---" << std::endl;
}
//TODO ask why Tile default constructor runs
void LinkedList::add(Tile tile)
{
  Node *node = new Node(tile, nullptr);
  if (head == nullptr)
  {
    head = node;
    tail = node;
    //std::cout << "head is " << head->getValue()->getShape() << std::endl;
  }
  else
  {
    tail->setNext(node);
    tail = node;
  }
  //std::cout << "head is " << head->getValue()->getShape();
}

Tile *LinkedList::takeFirst()
{
  Tile *first = head->getValue();
  head = head->getNext();
  return first;
}

Tile *LinkedList::takeTile(char colour, int shape)
{
  Tile *target = nullptr;
  Node *currentNode = head;
  while (currentNode->getNext() != nullptr)
  {
    int tileShape = currentNode->getNext()->getValue()->getShape();
    char tileCol = currentNode->getNext()->getValue()->getColour();
    if (tileCol == colour && tileShape == shape)
    {
      Node *newNext = currentNode->getNext()->getNext();
      target = currentNode->getNext()->getValue();
      currentNode->setNext(newNext);
      return target;
      //TODO figure out deletion
      //delete newNext;
    }
    else
    {
      currentNode = currentNode->getNext();
    }
  }
  return nullptr;
}

Tile *LinkedList::get(char colour, int shape)
{
  Node *currentNode = head;
  Tile *output = nullptr;
  while (currentNode != nullptr)
  {
    //check if current node matches args, if it don't currentNode = currentNode.getNext()
    int tileShape = currentNode->getValue()->getShape();
    char tileCol = currentNode->getValue()->getColour();
    if (tileCol == colour && tileShape == shape)
    {
      output = currentNode->getValue();
      return output;
    }
    else
    {
      currentNode = currentNode->getNext();
    }
  }
  return nullptr;
}
