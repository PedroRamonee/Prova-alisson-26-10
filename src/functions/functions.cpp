#include "functions.hpp"

void lista0() {
	vector<string> arquivo;
	vector<Carro> carros;
	arquivo = GerenciadoDeArquivo::carregaAquivo("arc/lista0.csv");

	for (int i = 0; i < arquivo.size(); i++) {
		Carro novo(arquivo[i]);
		carros.push_back(novo);
	}

	cout << "\n\nLista0.CSV: \n\n" << endl;

	shellsort<Carro>(carros);

	int idPesquisa;

	int resultado;

	cout << "Digite o ID do carro que deseja procurar:" << endl;
	cin >> idPesquisa;

	// QUESTÃO 1
	/*for (int i = 0; i < carros.size(); i++) {
	 if (carros[i] == idPesquisa) {
	 resultado = i;
	 }

	 }*/

	//QUESTÃO 3
	resultado = findLinear(carros, idPesquisa);

	cout << "O carro de chave " << idPesquisa << " é o:\n"
			<< carros[resultado].toString() << endl;
}

void lista2() {
	vector<string> arquivo;
	vector<Aluno> alunos;
	arquivo = GerenciadoDeArquivo::carregaAquivo("arc/lista2.csv");

	for (int i = 0; i < arquivo.size(); i++) {
		Aluno novo(arquivo[i], ';');
		alunos.push_back(novo);
	}

	cout << "\n\nLista2.CSV: \n\n" << endl;

	shellsort<Aluno>(alunos);

	TabelaHash<Aluno> Hash(11);

	for (unsigned int i = 0; i < alunos.size(); i++) {
		Hash.insere(alunos[i]);
	}

	int idPesquisa;

	int resultado;
	cout << "Digite a matricula do aluno que deseja procurar:" << endl;
	cin >> idPesquisa;

	Aluno pesquisar;

	pesquisar = Hash.pesquisa(idPesquisa);

	cout << pesquisar.toString() << endl;
}

void lista0Hash() {
	vector<string> arquivo;
	vector<Carro> carros;
	arquivo = GerenciadoDeArquivo::carregaAquivo("arc/lista0.csv");

	for (int i = 0; i < arquivo.size(); i++) {
		Carro novo(arquivo[i]);
		carros.push_back(novo);
	}

	cout << "\n\nLista2.CSV: \n\n" << endl;

	shellsort<Carro>(carros);

	TabelaHash<Carro> Hash(11);

	for (unsigned int i = 0; i < carros.size(); i++) {
		Hash.insere(carros[i]);
	}

	int idPesquisa;

	int resultado;
	cout << "Digite o ID do carro que deseja procurar:" << endl;
	cin >> idPesquisa;

	Carro pesquisar;

	pesquisar = Hash.pesquisa(idPesquisa);

	cout << pesquisar.toString() << endl;
}

void lista2Linear() {
	vector<string> arquivo;
	vector<Aluno> alunos;
	arquivo = GerenciadoDeArquivo::carregaAquivo("arc/lista2.csv");

	for (int i = 0; i < arquivo.size(); i++) {
		Aluno novo(arquivo[i], ';');
		alunos.push_back(novo);
	}

	cout << "\n\nLista0.CSV: \n\n" << endl;

	shellsort<Aluno>(alunos);

	int idPesquisa;

	int resultado;

	cout << "Digite a matricula do aluno que deseja procurar:" << endl;
	cin >> idPesquisa;


	resultado = findLinear(alunos, idPesquisa);

	cout << "O aluno de matricula " << idPesquisa << " é o(a):\n"
			<< alunos[resultado].toString() << endl;
}
