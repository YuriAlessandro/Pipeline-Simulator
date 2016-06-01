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
        std::string getName();
        std::string getDest();
        std::string getOp1();
        std::string getOp2();
        
        //print method
        void print( /* Empty */ );
};

#include "instruction.inl"

#endif