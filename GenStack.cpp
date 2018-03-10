/*
#include "GenStack.h"

using namespace std;




GenStack::GenStack(int maxSize)
{
  Stack = new char[maxSize];
  max = maxSize;
  top = -1;
  size= 0;
}

GenStack::~GenStack()
{
  //need to delete array
  cout << "object destroyed" << endl;
}

void GenStack::push(char data)
{
  //error checking (is the array full?)
  size++;
  myArray[++top] = data;
}

char GenStack::pop()
{
  //error checking: check if the element exist
  return Stack[top--];
  size--;
}

char GenStack::peek()
{
  return Stack[top];
}

int GenStack::isFull()
{
  return (top == max-1);
}

int GenStack::isEmpty()
{
  return (top == -1);
}
*/
