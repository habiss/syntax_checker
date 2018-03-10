#include <iostream>
#include <stdexcept>

using namespace std;

/*--Stack Template Definition--*/
template <typename T>
class GenStack
{
    enum { DEF_CAPACITY = 100 };//Default array size

  public:
    GenStack(int cap = DEF_CAPACITY);
    ~GenStack();

    void push(const T& data);
    T& pop();
    T& top() const;
    int getSize() const;
    int getCap();
    bool isEmpty() const;
    bool isFull() const;
    void expandArray();
    void print();

  private:
    T* Stack;
    int t; //top
    int capacity;
};

/*--STACK TEMPLATE IMPLEMENTATION--*/
//Default Constructor
template <typename T>
GenStack<T>::GenStack(int cap)
: Stack(new T[cap]), capacity(cap), t(-1) { }

template <typename T>
GenStack<T>::~GenStack() {
  delete [] Stack;
}

template <typename T>
int GenStack<T>::getSize() const
{ return (t + 1); }

template <typename T>
int GenStack<T>::getCap()
{ return capacity; }

template <typename T>
bool GenStack<T>::isEmpty() const
{ return (t < 0); }

template <typename T>
bool GenStack<T>::isFull() const
{
    return (t >= getSize());
}

//increase size
template <typename T>
void GenStack<T>::expandArray()
{
  T* tempArray = new T[capacity*2];

  for (int i=0; i < capacity; ++i)
  {
    tempArray[i] = Stack[i];
  }

  delete [] Stack;
  Stack = tempArray;
  capacity *= 2;
}

//top function
template <typename T>
T& GenStack<T>::top() const
{
  if (isEmpty())
  {
    throw std::invalid_argument( "Stack is empty.." );
  }
  return Stack[t];
}

//push function
template <typename T>
void GenStack<T>::push(const T& data)
{
  if (isFull())
  {
    expandArray();
    //throw std::invalid_argument( "Cannot push item. Stack is full!" );
  }
  Stack[++t] = data;
}

//print
template <typename T>
void GenStack<T>::print()
{
  for(int i=0; i<=t; ++i)
  {
    cout << i << ": " << Stack[i] << endl;
  }
}

//pop function
template <typename T>
T& GenStack<T>::pop()
{
  if (isEmpty())
  {
    throw std::invalid_argument( "Nothing to pop. Stack is empty." );
  }
  T& popTemp = Stack[t];
  --t;
  return popTemp;
}
