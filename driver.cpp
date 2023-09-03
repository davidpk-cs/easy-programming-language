#include "easy.h"
#include "components.cpp"
#include <iostream>


int main(){


    using std::string;
    using std::cout;

    string easyCode = fileReader("test.easy");

    easy program = easy(easyCode);

    program.processCode();


    return 0;

}
