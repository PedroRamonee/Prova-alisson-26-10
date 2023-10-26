/*
 * main.cpp
 *
 *  Created on: 26 de out de 2023
 *      Author: user
 */


#include "src/controller/gerenciador.hpp"
#include "src/functions/functions.hpp"


int main(int argc, char **argv) {

	 int escolha;

	    do {
	        // Apresenta o menu
	        std::cout << "MENU:" << std::endl;
	        std::cout << "1. Lista de carros Linear (lista0)" << std::endl;
	        std::cout << "2. Lista de alunos Hash (lista2)" << std::endl;
	        std::cout << "3. Lista de carros Hash (lista0)" << std::endl;
	        std::cout << "4. Lista de alunos Linear (lista2)" << std::endl;
	        std::cout << "0. Sair" << std::endl;
	        std::cout << "Escolha uma opção: ";
	        std::cin >> escolha;

	        // Realiza a ação de acordo com a escolha do usuário
	        switch (escolha) {
	            case 1:
	                lista0();
	                break;
	            case 2:
	            	lista2();
	                break;
	            case 3:
	            	lista0Hash();
	            	break;
	            case 4:
					lista2Linear();
					break;
	            case 0:
	                std::cout << "Saindo do programa." << std::endl;
	                break;
	            default:
	                std::cout << "Opção inválida. Tente novamente." << std::endl;
	                break;
	        }
	    } while (escolha != 0);

	return 0;
}


