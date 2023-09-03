#include <iostream>
#include <map>
#include <regex>
#include <fstream>

using std::string;
using std::map;

class easy{

    public:

        easy(string stringedCode){

            easyCode = stringedCode;

        }

        void processCode();

    private:

        string easyCode;


};
