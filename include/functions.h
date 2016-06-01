#ifndef _FUNCTIONS_
#define _FUNCTIONS_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "queue.h"
#include "instruction.h"

bool readFile( std::string & _filename, 
                std::vector<Instruction> & inst_vec);
                
void analysis( std::vector<Instruction> inst_vec );

#include "functions.inl"

#endif