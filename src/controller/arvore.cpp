#include "gerenciador.hpp"

using namespace std;

// Classe para armazenar o dado.
template <typename T>
class TipoItem {
   public:
    T valor;  // Troque pelo tipo de dado ou classe usada.
              //  O ideal � que a classe tenha <>== e toString.

    // Construtores para auxiliar o uso.
    TipoItem() : valor() {}
    TipoItem(T novoValor) : valor(novoValor) {}
    // Sobrecarga dos operadores de compara��o.

    bool operator>(const TipoItem &outro) { return valor > outro.valor; }
    bool operator<(const TipoItem &outro) { return valor < outro.valor; }
    bool operator==(const TipoItem &outro) { return valor == outro.valor; }
    string toString() {
        return valor.toString();
        // ou apague tudo e retorne o toString da
        // classe como em:
        // return aluno.toString();
    }
};

// definindo o n� da arvore
template <typename T>
class No {
   public:
    TipoItem<T> info;
    No *esq;
    No *dir;
};

// definindo a estrutura da arvore
template <typename T>
class Arvore {
   public:
    No<T> *raiz;

    // Cria��o da �rvore
    // Arv* abb_cria(void)
    Arvore() { raiz = NULL; }

    // Inser��o de um n�
    void insere(TipoItem<T> v) { raiz = abb_insere(raiz, v); }

    void imprime() { abb_imprime(raiz); }

   private:
    No<T> *abb_insere(No<T> *a, TipoItem<T> v) {
        if (a == NULL) {
            a = new No<T>;
            a->info = v;
            a->esq = a->dir = NULL;
        } else if (v < a->info)
            a->esq = abb_insere(a->esq, v);
        else
            /* v > a->info */
            a->dir = abb_insere(a->dir, v);
        return a;
    }

    // impress�o dos dados da �rvore

    void abb_imprime(No<T> *a) {
        if (a != NULL) {
            abb_imprime(a->esq);
            printf("%s\n", a->info.toString().c_str());
            abb_imprime(a->dir);
        }
    }
};
