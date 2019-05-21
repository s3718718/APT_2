
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

// bool LinkedList::isEmpty()
// {
//   output = false;
//   if (head == nullptr)
//   {
//     output = true;
//   }
//   return output;
// }

std::string LinkedList::toString()
{
  Node *currentNode = head;
  // Tile *output == nullptr;
  std::string output = "";
  bool firstItem = true;
  while (currentNode != nullptr)
  {
    if (!firstItem)
    {
      output.append(", ");
    }
    //check if current node matches args, if it don't currentNode = currentNode.getNext()
    int tileShape = currentNode->getValue()->getShape();
    char tileCol = currentNode->getValue()->getColour();
    std::string tileColString(1, tileCol);
    output.append(tileColString);
    output.append(std::to_string(tileShape));
    currentNode = currentNode->getNext();
    firstItem = false;
  }
  return output;
}

void LinkedList::printList()
{
  bool first = true;
  std::cout << "Size of list : " << this->getSize() << std::endl;
  Node *currentNode = head;
  // Tile *output == nullptr;
  std::cout << "---LinkedList Contents---" << std::endl;
  while (currentNode != nullptr)
  {
    if (!first)
    {
      std::cout << ", ";
    }
    else
    {
      //check if current node matches args, if it don't currentNode = currentNode.getNext()
      //  Shape tileShape = currentNode->getValue()->getShape();
      //  Colour tileCol = currentNode->getValue()->getColour();
      //std::cout << "\e[31mred"<<tileCol << tileShape << std::endl;
      currentNode->getValue()->printColoured();
      currentNode = currentNode->getNext();
    }
  }
  std::cout << "---End---" << std::endl;
}
//TODO ask why Tile default constructor runs
void LinkedList::add(Tile *tile)
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

Tile *LinkedList::takeTile(Colour colour, Shape shape)
{
  std::cout << "take tile input = " << colour << shape << std::endl;
  Tile *target = nullptr;
  Node *currentNode = head;

  if (head->getValue()->getColour() == colour && head->getValue()->getShape() == shape)
  {
    target = head->getValue();
    head = head->getNext();
    std::cout << "found in first" << std::endl;
  }
  else
  {
    bool notFound = true;
    while (currentNode->getNext() != nullptr)
    {

      int tileShape = currentNode->getNext()->getValue()->getShape();
      char tileCol = currentNode->getNext()->getValue()->getColour();
      std::cout << "checking input: " << colour << shape << " vs current: " << tileCol << tileShape << std::endl;
      if (tileCol == colour && tileShape == shape && notFound)
      {
        std::cout << "found in loop" << std::endl;
        //TODO this might break when there's 2 of each tile. If it does, change it so that this rearrangement happens only at the end of the loop.
        Node *newNext = currentNode->getNext()->getNext();
        target = currentNode->getNext()->getValue();
        currentNode->setNext(newNext);
        notFound = false;
      }
      else
      {
        currentNode = currentNode->getNext();
      }
    }
  }
  std::cout << "target col = " << std::endl;
  std::cout << target->getColour() << std::endl;
  return target;
}

Tile *LinkedList::get(Colour colour, Shape shape)
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
  int len = this->getSize();
  Tile *tileArray[len];
  int i = 0;
  Node *currentNode = head;
  srand(time(0));
  //std::cout<<"Converting to Array"<<std::endl;
  while (currentNode != nullptr)
  {
    // std::cout<<"Adding to array at : "<<i<<std::endl;
    tileArray[i] = currentNode->getValue();
    currentNode = currentNode->getNext();
    i++;
  }

  Tile *temp;
  int randomIndex = 0;
  // Shuffling the array
  for (int i = 0; i < len; i++)
  {
    randomIndex = rand() % len; //Generate a random position
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
