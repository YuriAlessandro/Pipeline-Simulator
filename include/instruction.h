#ifndef _INSTRUCTION_
#define _INSTRUCTION_

#include <iostream>
#include <string>
#include <vector>

class Instruction
{
    private:
        std::string m_name;
        std::string m_dest;
        std::string m_op1;
        std::string m_op2;

    public:
        //Constructor
        Instruction( std::string );
        
        //Disabling constructor without parameters
        
        //Destructor
        //~Instruction ( );
        
        //Getters
        std::string getName( /* Empty */ );
        std::string getDest( /* Empty */ );
        std::string getOp1( /* Empty */ );
        std::string getOp2( /* Empty */ );
        
        //print method
        void print( /* Empty */ );
};

#include "instruction.inl"

#endif