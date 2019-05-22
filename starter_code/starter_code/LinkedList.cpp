
#include "LinkedList.h"
#include <iostream>
#include <ctime>

//TODO: Rewrite code to comply with structured programming

LinkedList::LinkedList()
{
  head = nullptr;
  tail = nullptr;
  this->outputStream = &std::cout;
}

LinkedList::LinkedList(std::ostream *outputStream)
{
  head = nullptr;
  tail = nullptr;
  this->outputStream = outputStream;
}

LinkedList::~LinkedList()
{
}

bool LinkedList::isEmpty()
{
  bool output = false;
  if (head == nullptr)
  {
    output = true;
  }
  return output;
}

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
    Shape tileShape = currentNode->getValue()->getShape();
    Colour tileCol = currentNode->getValue()->getColour();
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
  // *outputStream << "Size of list : " << this->getSize() << std::endl;
  Node *currentNode = head;
  // Tile *output == nullptr;
  // *outputStream << "---LinkedList Contents---" << std::endl;
  while (currentNode != nullptr)
  {
    if (!first)
    {
      *outputStream << ", ";
    }
    currentNode->getValue()->printColoured();
    currentNode = currentNode->getNext();
    first = false;
  }
  *outputStream << std::endl;
  //  *outputStream << "---End---" << std::endl;
}
//TODO ask why Tile default constructor runs
void LinkedList::add(Tile *tile)
{
  Node *node = new Node(tile, nullptr);
  if (head == nullptr)
  {
    //*outputStream << "head is nullptr" << std::endl;
    head = node;
    tail = node;
    //*outputStream << "head is " << head->getValue()->getShape() << std::endl;
  }
  else
  {
    //*outputStream << "adding node to tail" << std::endl;
    tail->setNext(node);
    tail = node;
  }
  //*outputStream << "head is " << head->getValue()->getShape();
}

Tile *LinkedList::takeFirst()
{
  Tile *first = head->getValue();
  head = head->getNext();
  return first;
}

Tile *LinkedList::takeTile(Colour colour, Shape shape)
{
  // *outputStream << "take tile input = " << colour << shape << std::endl;
  Tile *target = nullptr;
  Node *currentNode = head;

  if (head->getValue()->getColour() == colour && head->getValue()->getShape() == shape)
  {
    target = head->getValue();
    head = head->getNext();
    // *outputStream << "found in first" << std::endl;
  }
  else
  {
    bool notFound = true;
    while (currentNode->getNext() != nullptr)
    {

      Shape tileShape = currentNode->getNext()->getValue()->getShape();
      Colour tileCol = currentNode->getNext()->getValue()->getColour();
      //*outputStream << "checking input: " << colour << shape << " vs current: " << tileCol << tileShape << std::endl;
      if (tileCol == colour && tileShape == shape && notFound)
      {
        //*outputStream << "found in loop" << std::endl;
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
    //Checks whether or not the tail value was the one selected. If so, it updates the tail value accordingly
    if (!notFound && tail->getValue()->getColour() == target->getColour() && tail->getValue()->getShape() == target->getShape())
    {
      tail = currentNode;
    }
  }
  //*outputStream << "target col = " << std::endl;
  //*outputStream << target->getColour() << std::endl;
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
    }
    else
    {
      currentNode = currentNode->getNext();
    }
  }
  return output;
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
    store = currentNode->getNext();
    delete currentNode;
    currentNode = store;
  }
  head = nullptr;
}

void LinkedList::shuffle()
{
  int len = this->getSize();
  Tile *tileArray[len];
  int i = 0;
  Node *currentNode = head;
  //Uncomment to get truly random shuffle
  //srand(time(0));

  while (currentNode != nullptr)
  {
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
  // Adding shuffled tiles back to linked list
  for (int i = 0; i < len; i++)
  {
    this->add(tileArray[i]);
  }
}
