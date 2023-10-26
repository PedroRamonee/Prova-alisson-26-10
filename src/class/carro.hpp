#ifndef SRC_CARRO_HPP_
#define SRC_CARRO_HPP_

#include "../controller/gerenciador.hpp"

class Carro {
private:
	int id;
	string montadora;
	int cilindradas;

public:
	Carro();
	Carro(int id);

	Carro(string line);

	string toString();

	bool operator>(const Carro &outroCarro) {
		return id > outroCarro.id;
	}
	bool operator<(const Carro &outroCarro) {
		return id < outroCarro.id;
	}
	bool operator==(const Carro &outroCarro) {
		return id == outroCarro.id;
	}
	bool operator!=(const Carro &outroCarro) {
		return id != outroCarro.id;
	}
	int operator%(const int &X) {
		return id % X;
	}
	bool operator==(const int &X) {
		return id == X;
	}
};

#endif /* SRC_CARRO_HPP_ */
