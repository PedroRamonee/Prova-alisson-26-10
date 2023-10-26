/*
 * TabelaHash.hpp
 *
 *  Created on: 28 de set de 2023
 *      Author: user
 */

#ifndef TABELAHASH_HPP_
#define TABELAHASH_HPP_

#include <iostream>
#include <vector>
#include "aluno.hpp"

using namespace std;

class Celula {
public:
	Aluno chave;
	Celula(Aluno chave) {
		this->chave = chave;
	}
};

class TabelaHash {
private:
	int tamanho;
	vector<vector<Celula> > tabela;

	int getMod(Aluno chave) {
		return chave % tamanho;
	}
	void imprimeLista(vector<Celula> lista) {
		for (unsigned int i = 0; i < lista.size(); i++) {

			cout << lista[i].chave.toString();
			if (i + 1 != lista.size()) {
				cout << "- ";
			}
		}
	}
	Aluno retiraLista(vector<Celula> lista, Aluno chave) {
		for (unsigned int i = 0; i < lista.size(); i++) {
			if (lista[i].chave == chave) {
				lista.erase(lista.begin() + i);
				return chave;
			}
		}

	}
	int pesquisaLista(vector<Celula> lista, int chave) {
		for (unsigned int i = 0; i < lista.size(); i++) {
			if (lista[i].chave == chave) {
				return i;
			}
		}
		return -1;

	}
public:
	TabelaHash(int tamanho) {
		this->tamanho = tamanho;

		for (int i = 0; i < tamanho; i++) {
			vector<Celula> lista;
			tabela.push_back(lista);
		}
	}
	Aluno pesquisa(int chave) {
		int i = chave % tamanho;

		if (tabela[i].empty()) {

		} else {
			int item = pesquisaLista(tabela[i], chave);

			if (item == -1) {

				return -1;
			} else {
				return tabela[i][item].chave;
			}
		}
	}
	void insere(Aluno chave) {

		int i = getMod(chave);
		tabela[i].push_back(Celula(chave));

	}
	Aluno retira(Aluno chave) {
		int i = this->getMod(chave);

		Aluno item = retiraLista(tabela[i], chave);

		if (item == -1) {
			cout << "Item não está presente" << endl;

		} else {

			return item;
		}
	}
	void imprime() {
		cout << "Hash de modulo % " << tamanho << endl;
		for (int i = 0; i < tamanho; i++) {

			cout << "h = " << i << "[";
			imprimeLista(tabela[i]);
			cout << "]" << endl;
		}
	}
};

#endif /* TABELAHASH_HPP_ */
