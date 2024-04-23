#include <iostream>
#include "Debugger.h"
#include <string>
using std::string;

int main(int argc, char *argv[])
{
    string fileName = argv[1];

    Debugger debuggerObj;

    debuggerObj.checkBrackets(fileName);

    return 0;
}
