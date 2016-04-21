#include <iostream>
#include <fstream>
#include <string>
#include <vector>


bool readFile( std::string _filename, 
                std::vector<std::string> & instructions ) {

    std::string line;
    
    std::ifstream file(_filename);
    if( ! file.is_open() ){
        std::cout << "Something went wrong with de read file...\n";
        return false;
    }
    
    while( !file.eof() && file >> line ){
        instructions.push_back(line);
    }

    file.close();
    return true;
}