#include "Debugger.h"
#include <fstream>
#include <iostream>
#include <string>

using std::string;
using std::ifstream;
using std::cerr;
using std::cout;
using std::getline;
using std::endl;

Debugger::Debugger()
{
    //ctor
}

void Debugger::checkBrackets(string filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    string line;
    int lineNumber = 1;
      while (getline(file, line)) {
        for(int i = 0; i < line.size(); ++i) {
            char symbol = line[i];
            if(symbol == '[' || symbol == '{' || symbol == '('){

                    bool bracketIClosed = isClosingBracketFound(filePath, symbol, lineNumber, i);
                    if(!bracketIClosed){
                        cout << "Invalid bracket "  << symbol << "found at " << filePath << ":" << lineNumber << ":" << i+1;
                        return;
                    }
               }
        }
        lineNumber++;
      }

      file.close();
}

bool Debugger::isClosingBracketFound(string filePath, char bracketType, int bracketLineNumber, int bracketColumnNumber) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return false;
    }

    char closingBracket;

    switch(bracketType) {
      case '[':
        closingBracket = ']';
        break;
      case '{':
        closingBracket = '}';
        break;
      case '(':
        closingBracket = ')';
        break;
    }

    string line;
    int lineNumber = 1;
      while (getline(file, line)) {
            if(lineNumber < bracketLineNumber){
                continue;
            }
        for(int i = 0; i < line.size(); ++i) {
                if(i <= bracketColumnNumber){
                    continue;
                }

            char symbol = line[i];
            if(symbol == bracketType){
                file.close();
                return false;
            }
            if(symbol == closingBracket){
                file.close();
                return true;
            }
        }
        lineNumber++;
      }

      file.close();
      return false;
}
