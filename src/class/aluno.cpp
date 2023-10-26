#include "aluno.hpp"

Aluno::Aluno() {
    this->matricula = 0;
    this->sobrenome = "";
    this->nome = "";
}

Aluno::Aluno(int id) {
    this->matricula = id;
    this->sobrenome = "";
    this->nome = "";
}

Aluno::Aluno(string arquivo, char delimiter = ';') {
    string dado;
    stringstream ss(arquivo);  // stringstream => 	<sstream>

    getline(ss, dado, delimiter);
    matricula = atoi(dado.c_str());

    getline(ss, dado, delimiter);
    nome = (dado);

    getline(ss, dado, delimiter);
    sobrenome = (dado);
}

string Aluno::toString() {
    stringstream ss;
    ss << nome <<" "<< sobrenome;
    return ss.str();
}
