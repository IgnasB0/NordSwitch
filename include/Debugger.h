#ifndef DEBUGGER_H
#define DEBUGGER_H
#include <string>
using std::string;
class Debugger
{
    public:
        Debugger();
        void checkBrackets(string filePath);
    protected:

    private:
        bool isClosingBracketFound(string filePath, char bracketType, int bracketLineNumber, int bracketColumnNumber);
};

#endif // DEBUGGER_H
