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


int main(int argc, char const *argv[]){
	
	std::string filename;

	if (argc > 1){
		fileName = argv[1];
	}else{
		std::cout << ">>> WARNING: Filename not set.\n";
		std::cout << ">>> Please, try again with < $ ./EX <filename>\n";
		return EXIT_FAILURE;
	}

	

	return EXIT_SUCESS;
}
