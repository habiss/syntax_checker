//#include <string>
#include <iostream>

class SyntaxChecker
{
  public:
    SyntaxChecker();
    ~SyntaxChecker();
    bool isMatched(char open, char close);
    char isExpected(char top);
};
