#include "easy.h"
#include "components.cpp"
#include <vector>

using std::string;
using std::vector;
using std::cout;


void easy::processCode(){

    vector <string> codeLines;

    while(easyCode != "exit" && easyCode != " "){

        codeLines.push_back(breakString(easyCode));

        cout << codeLines.back() << "\n";
    }
}