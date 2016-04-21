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

#include "functions.cpp"

int main(int argc, char const *argv[]){
	
	/* Nome do arquivo com as intruções a serem analisadas. */
	std::string filename;
	std::vector<std::string> instructions; 

	/* Recebe o nome do arquivo por parâmetro, roda o caso
	 * padrão caso não seja inserido. */
	if (argc > 1){
		filename = argv[1];
	}else{
		std::cout << ">>> WARNING: filename not set.\n";
		std::cout << ">>> Please, try again with < $ ./EX <filename>\n";
		return EXIT_FAILURE;
	}
	
	if( !readFile( filename, instructions ) ){
		std::cout << ">>> ERROR: File not found\n";
		return EXIT_FAILURE;
	}
	
	std::cout << "The instructions read are:\n";
	
	for (unsigned int i(0); i < instructions.size(); i++) {
		if (i % 4 == 0 and i != 0) std::cout << std::endl;	//Boa
		std::cout << instructions.at(i) << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
