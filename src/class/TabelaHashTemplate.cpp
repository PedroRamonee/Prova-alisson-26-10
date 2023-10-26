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

using namespace std;
template<typename T>
class Celula {
public:
	T chave;
	Celula(T chave) {
		this->chave = chave;
	}
};

template<typename T>
class TabelaHash {
private:
	int tamanho;
	vector<vector<Celula<T> > > tabela;

	int getMod(T chave) {
		return chave % tamanho;
	}
	void imprimeLista(vector<Celula<T> > lista) {
		for (unsigned int i = 0; i < lista.size(); i++) {

			cout << lista[i].chave.toString();
			if (i + 1 != lista.size()) {
				cout << "-";
			}
		}
	}
	T retiraLista(vector<Celula<T> > lista, T chave) {
		for (unsigned int i = 0; i < lista.size(); i++) {
			if (lista[i].chave == chave) {
				lista.erase(lista.begin() + i);
				return chave;
			}
		}
	}
	int pesquisaLista(vector<Celula<T> > lista, int chave) {
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
			vector<Celula<T> > lista;
			tabela.push_back(lista);
		}
	}
	T pesquisa(int chave) {
		int i = this->getMod(chave);

		if (tabela[i].empty()) {

			return -1;
		} else {
			int item = pesquisaLista(tabela[i], chave);

			if (item == -1) {
				return item;
			} else {
				return tabela[i][item].chave;
			}
		}
	}
	void insere(T chave) {

		int i = getMod(chave);
		tabela[i].push_back(Celula<T>(chave));

	}
	T retira(T chave) {
		int i = this->getMod(chave);

		T item = retiraLista(tabela[i], chave);

		if (item == -1) {
			cout << "Item não está presente" << endl;
			return -1;
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
