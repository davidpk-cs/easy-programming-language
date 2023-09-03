#include <string>
#include <fstream>
#include <streambuf>


// code pulled from https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c
std::string fileReader(std::string fileName){
  
    std::ifstream t(fileName);

    if (!t.is_open()) {
    std::cerr << "Failed to open file: " << fileName << std::endl;
    return ""; // Return an empty string to indicate failure.
    }
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());


    return str;

}

//code pulled from https://devptr.com/check-if-string-is-empty-or-whitespace-in-c/
bool isStringEmptyOrWhitespace(const std::string& str) {
    // Check if the string is empty
    if (str.empty()) {
        return true;
    }
    // Check if all characters in the string are whitespace
    return std::all_of(str.begin(), str.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });
}


//This function will extract a line of code, which is denoted by being its own line
//so in otherwords, \n indicates the end of a line
//this program also takes care of exits
std::string breakString(std::string &theString){

    std::string brokenString = "";

    //this turns true once brokenString has started parsing characters
    //once that happens it means spaces in between matter
    bool gotCharFlag = false; 


    if(theString.empty()){
        return "exit";
    }


    for(int i = 0; i < theString.size(); i++){

    
        if(theString[i] != ' '){

            //once we encounter a newline
            //line parsing is finished
            if(theString[i] == '\n'){

                if(i + 1 < theString.size()){

                    //strip of the part of the code that was read already
                    theString = theString.substr(i);

                }
            }
            else{
                brokenString += theString[i];
                gotCharFlag = true;
            }

        }

        //these checks make sure I don't add excessive spacing when parsing a line of code
        else if(gotCharFlag = true && brokenString[brokenString.size() - 1] != ' '){
            brokenString += " ";
        }

    }

    //if the function does not return prior to arriving here, that means the end of the string was parsed
    //and as such, the end of the file that was read into here.
    //verify that there wasn't a line of code read in and return accordingly
    if(gotCharFlag){
        return brokenString;
    }
    return "exit";
}