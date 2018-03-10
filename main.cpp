#include "GenStack.h"
#include "SyntaxChecker.h"
#include <fstream>
//#include <string>
#include <sstream>

using namespace std;

//main
int main(int argc , char** argv)
{
  GenStack <char> S(100);
  SyntaxChecker SC;
  stringstream errorMsg;
  string fileName;
  string line;
  int countLine = 0;
  bool errorFree = true;
  bool validFile = false;

  try {
    //file input
    //cout << S.getCap() << endl;
    while(validFile == false)
    {
    cout << "Enter file name and location to analyze the source code: " << endl;
    cin >> fileName;
    ifstream myFile(fileName);

    if(myFile.is_open())
    {
          cout << "Scanning file..." << endl;

      while( !myFile.eof() )
      {
        getline(myFile,line);
        countLine++;
        string aLine = line;

        for(int i = 0; i < aLine.size(); ++i)
        {
          //If opening bracket found add it to the stack
          if(aLine[i] == '[' || aLine[i] == '{' || aLine[i] == '(')
          {
            //cout << "push me " << endl;
            S.push(aLine[i]);
          }
          //If closing bracket found, check matching condition
          if(aLine[i] == ']' || aLine[i] == '}' || aLine[i] == ')')
          {
            //Check for extraneous braces
            if( S.isEmpty() )
            {
              errorMsg << "! Extraneous closing brace '" << aLine[i] << "' found at " << countLine << ":" << i+1 << endl;
              errorFree = false;
            }

            //Check if opening and closing brackets match
            else if(SC.isMatched(S.top(), aLine[i]))
                {
                  //cout << "Pop me " << endl;
                  S.pop(); //normalizes brackets in the stack
                }
            else
              {
                //while(SC.isExpected(S.top()) != '-'){
                errorMsg << "! Expected '" << SC.isExpected(S.top()) << "' at " << countLine << ":" << i+1 <<endl;
                errorFree = false;
                //}
              }
          }
        }//end for
      }//end while
      myFile.close();
      validFile = true;
    }//end if
    else
    {
      cout << "File doesn't exist. Try again.." << endl;
    }
  }

    cout << "====================Scan Result==================" << endl;
    //S.print();
    cout << "Total lines scanned: " << countLine << endl;
    //cout << " Stack Capacity: " << S.getCap() << endl;

    if (S.isEmpty())
    {
      if(errorFree== true)
      {
        cout << "No syntax errors found." << endl;
      }

      cout << "=================================================" << endl;
    }
    else if (errorFree==false)
    {
      cout << "Warning! Syntax errors found:" << endl;
      cout << errorMsg.str();
      cout << "=================================================" << endl;
    }
    else
    {
      //check for unclosed brackets
      S.print();
      cout << "! Unclosed bracket at line " << countLine << endl;
      cout << "=================================================" << endl;
    }
  }

  catch(std::invalid_argument& e)
  { cout << e.what() << endl; }

return 0;
}//end main
