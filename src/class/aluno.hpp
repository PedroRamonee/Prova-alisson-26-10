#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "../controller/gerenciador.hpp"

class Aluno {
   private:
    int matricula;
    string nome;
    string sobrenome;

   public:
    Aluno();
    Aluno(int id);
    Aluno(string arquivo, char delimiter);
    string toString();

    bool operator>(const Aluno &outroAluno) { return matricula > outroAluno.matricula; }
    bool operator<(const Aluno &outroAluno) { return matricula < outroAluno.matricula; }
    bool operator==(const Aluno &outroAluno) { return matricula == outroAluno.matricula; }
    bool operator!=(const Aluno &outroAluno) { return matricula != outroAluno.matricula; }
    int operator%(const int &X){return matricula % X;}
    bool operator==(const int &X){return matricula == X;}
};

#endif
