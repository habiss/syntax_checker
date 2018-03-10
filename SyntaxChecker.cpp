#include "SyntaxChecker.h"
//#include <string>

using namespace std;

  SyntaxChecker::SyntaxChecker(){}
  SyntaxChecker::~SyntaxChecker()
  {
    cout << "Object destroyed." << endl;
  }
  //Matching brackets function
  bool SyntaxChecker::isMatched(char open, char close)
  {
    if ( open == '(' && close == ')'){
      return true;
       }
    if ( open == '[' && close == ']'){
      return true;
    }
    if ( open == '{' && close == '}'){
      return true;
    }
    else
    {
      return false;
    }
  }

  //Expected bracket symbol - used to show correction
  char SyntaxChecker::isExpected(char top)
  {
    if(top == '(')
      return ')';
    else if (top == '{')
      return '}';
    else if (top == '[')
      return ']';
    else return '-';
  }
