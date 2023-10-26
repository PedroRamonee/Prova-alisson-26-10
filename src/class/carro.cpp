#include "carro.hpp"

Carro::Carro() {
    this->id = 0;
    this->montadora = "";
    this->cilindradas = 0;
}

Carro::Carro(int id) {
    this->id = id;
    this->montadora = "";
    this->cilindradas = 0;
}

Carro::Carro(string line) {
    string dado;
    stringstream ss(line);  // stringstream => 	<sstream>

    getline(ss, dado, ',');
    this->id = atoi(dado.c_str());

    getline(ss, dado, ',');

    this->montadora = (dado);

    getline(ss, dado, ',');
    this->cilindradas = atoi(dado.c_str());

    getline(ss, dado, ',');
}

string Carro::toString() {
    stringstream ss;
    ss << id << "," << montadora << "," << cilindradas;
    return ss.str();
}
