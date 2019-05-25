#ifndef CONJUNTO_INDICE_H
#define CONJUNTO_INDICE_H
#include <cstring>
#include <vector>
#include "Conjunto.h"

using namespace std;

struct NO;

class Conjunto_Indice{
    private:
        NO* fim_;
        int cardinalidade_;
    public:
        //Cria um Conjunto vazio
        Conjunto_Indice();

        //Desaloca toda a memória alocada para o Conjunto.
        virtual ~Conjunto_Indice();

        //Insere a palavra 'p' contida no arquivo 'arq'. Se a palavra já foi inserida, insere o arquivo 'arq' em que ela está contida.
        //Se o arquivo também já foi inserido, a função não executa nada.
        void inserir(string p, string arq);

        //Remove a palavra 'p' se ela pertencer ao Conjunto.
        void remover(string p);

        //Verifica se a palavra 'p' pertence ao Conjunto.
        bool pertence(string p);

        //Verifica se o Conjunto 'x' é igual ao Conjunto corrente, mas não verifica a igualdade dos subconjuntos de arquivos.
        bool operator== (Conjunto_Indice& x);

        //Retorna o menor elemento do Conjunto. Pressupõe que o Conjunto não está vazio.
        string menor();

        //Verifica se a palavra 'p' está contida no arquivo 'arq'. Pressupõe que 'p' pertence ao Conjunto.
        bool pertenceArquivo(string p, string arq);

        //Verifica se o Conjunto está vaio.
        bool vazio();

        //Retorna a quantidade de elementos que existem no Conjunto.
        int cardinalidade();
};

#endif // CONJUNTO_INDICE_H
