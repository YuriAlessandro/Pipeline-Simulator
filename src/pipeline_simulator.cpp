/**
 *  \mainpage Pipeline Simulator
 *  \author Yuri Alessandro Martins e Yuri Reinaldo da Silva
 *  \date 2016
 *  \version 1.0
 *
 *  \file pipeline_simulator.cpp
 *  \brief EXPLICAR O QUE O ARQUIVO FAZ.
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "functions.h"

int main(int argc, char const *argv[])
{
	std::system("clear");
	
	/* Nome do arquivo com as intruções a serem analisadas. */
	std::string filename;
	std::vector<Instruction> inst_vec; 

	/* Recebe o nome do arquivo por parâmetro, roda o caso
	 * padrão caso não seja inserido. */
	
	std::cout << "Preparing to read \"" << argv[1] << "\" file.\n";
	
	if (argc > 1)
	{
		filename = argv[1];
	}
	
	else
	{
		std::cout << ">>> WARNING: filename not set.\n";
		std::cout << ">>> Please, try again with < $ ./EX [filename]\n";
		return EXIT_FAILURE;
	}
	
	if( !readFile( filename, inst_vec ) )
	{
		std::cout << ">>> ERROR: File not found\n";
		return EXIT_FAILURE;
	}
	std::cout << "File opened successfully!\n";
	std::cout << "Generating Pipeline...\n";
	
	analysis( inst_vec );
	
	return EXIT_SUCCESS;
}
