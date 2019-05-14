
#include "LinkedList.h"
#include <iostream>
#include <ctime>

//TODO: Rewrite code to comply with structured programming

LinkedList::LinkedList()
{
  head = nullptr;
  tail = nullptr;
}

LinkedList::~LinkedList()
{
}

std::string LinkedList::toString()
{
  Node *currentNode = head;
  // Tile *output == nullptr;
  std::string output = "";
  while (currentNode != nullptr)
  {

    //check if current node matches args, if it don't currentNode = currentNode.getNext()
    int tileShape = currentNode->getValue()->getShape();
    char tileCol = currentNode->getValue()->getColour();
    std::string tileColString(1, tileCol);
    output.append(tileColString);
    output.append(std::to_string(tileShape));
    output.append(", ");
    currentNode = currentNode->getNext();
  }
  return output;
}

void LinkedList::printList()
{
  std::cout << "Size of list : " << this->getSize() << std::endl;
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

int LinkedList::getSize()
{
  Node *currentNode = head;
  int counter = 0;
  while (currentNode != nullptr)
  {
    currentNode = currentNode->getNext();
    counter++;
  }
  return counter;
}

void LinkedList::deleteAll()
{
  Node *currentNode, *store;
  currentNode = head;
  while (currentNode != nullptr)
  {
    // std::cout<<"Deleting : "<<std::endl;
    store = currentNode->getNext();
    delete currentNode;
    currentNode = store;
    //  std::cout<<"Size of list : "<<this->getSize()<<std::endl;
  }
  head = nullptr;
}

// TODO : Refactor method
void LinkedList::shuffle()
{
  int len = 36;
  Tile *tileArray = new Tile[len];
  int i = 0;
  Node *currentNode = head;
  //std::cout<<"Converting to Array"<<std::endl;
  while (currentNode != nullptr)
  {
    // std::cout<<"Adding to array at : "<<i<<std::endl;
    tileArray[i] = *currentNode->getValue();
    currentNode = currentNode->getNext();
    i++;
  }

  Tile temp;
  int randomIndex = 0;
  // Shuffling the array
  for (int i = 0; i < len; i++)
  {
    randomIndex = rand() % len;
    temp = tileArray[i];
    tileArray[i] = tileArray[randomIndex];
    tileArray[randomIndex] = temp;
  }

  this->deleteAll();
  //std::cout<<"Size of list : "<<this->getSize()<<std::endl;
  // Adding shuffled tiles back to linked list
  for (int i = 0; i < len; i++)
  {
    // std::cout<<"Size of list : "<<this->getSize()<<std::endl;
    //  std::cout<<"Adding back to linked list at : "<<i<<std::endl;
    //  tileArray[i].printTile();
    this->add(tileArray[i]);
  }
  //std::cout<<"Size of list : "<<this->getSize()<<std::endl;
}