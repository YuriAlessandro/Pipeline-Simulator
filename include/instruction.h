#include <vector>

#ifndef _INSTRUCTION_
#define _INSTRUCTION_

class instructions
{
    private:
        std::string name;
        std::vector <std::string> operands (3);

    public:
        //Constructor
        instructions(std::vector <std::string>);
        
        //Disabling constructor without parameters
        instructions() = 0;
        
        //Destructor
        ~instructions ( ) 
        { 
            delete name;
            delete operands;
        }
        
        //Getters
        std::string getName ();
        std::vector<std::string> getOperands ();
}

#include "instruction.inl"

#endif