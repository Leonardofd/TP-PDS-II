#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <cstring>


using namespace std;

struct no;

class Conjunto{
   private:
        no* fim_;
        int cardinalidade_;
    public:
        //Cria um Conjunto vazio.
        Conjunto();

        //Desaloca toda a memória alocada para o Conjunto
        virtual ~Conjunto();

        //Insere a palavra 'p' se ela não pertence ao Conjunto.
        void inserir(string p);

        //Remove a palavra 'p' se ela pertencer ao Conjunto.
        void remover(string p);

        //Verifica se a palavra 'p' pertence ao Conjunto.
        bool pertence(string p);

        //Verifica se o Conjunto 'x' é igual ao Conjunto corrente.
        bool operator== (Conjunto& x);

        //Atribui o Conjunto 'x' ao Conjunto corrente.
        void operator= (Conjunto& x);

        //Retorna o menor elemento do Conjunto. Pressupõe que o Conjunto não está vazio.
        string menor();

        //Verifica se o Conjunto está vaio.
        bool vazio();

        //Retorna a quantidade de elementos que existem no Conjunto.
        int cardinalidade();
};

#endif // CONJUNTO_H
