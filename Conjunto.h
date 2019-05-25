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

        //Desaloca toda a mem�ria alocada para o Conjunto
        virtual ~Conjunto();

        //Insere a palavra 'p' se ela n�o pertence ao Conjunto.
        void inserir(string p);

        //Remove a palavra 'p' se ela pertencer ao Conjunto.
        void remover(string p);

        //Verifica se a palavra 'p' pertence ao Conjunto.
        bool pertence(string p);

        //Verifica se o Conjunto 'x' � igual ao Conjunto corrente.
        bool operator== (Conjunto& x);

        //Atribui o Conjunto 'x' ao Conjunto corrente.
        void operator= (Conjunto& x);

        //Retorna o menor elemento do Conjunto. Pressup�e que o Conjunto n�o est� vazio.
        string menor();

        //Verifica se o Conjunto est� vaio.
        bool vazio();

        //Retorna a quantidade de elementos que existem no Conjunto.
        int cardinalidade();
};

#endif // CONJUNTO_H
