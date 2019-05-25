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

        //Desaloca toda a mem�ria alocada para o Conjunto.
        virtual ~Conjunto_Indice();

        //Insere a palavra 'p' contida no arquivo 'arq'. Se a palavra j� foi inserida, insere o arquivo 'arq' em que ela est� contida.
        //Se o arquivo tamb�m j� foi inserido, a fun��o n�o executa nada.
        void inserir(string p, string arq);

        //Remove a palavra 'p' se ela pertencer ao Conjunto.
        void remover(string p);

        //Verifica se a palavra 'p' pertence ao Conjunto.
        bool pertence(string p);

        //Verifica se o Conjunto 'x' � igual ao Conjunto corrente, mas n�o verifica a igualdade dos subconjuntos de arquivos.
        bool operator== (Conjunto_Indice& x);

        //Retorna o menor elemento do Conjunto. Pressup�e que o Conjunto n�o est� vazio.
        string menor();

        //Verifica se a palavra 'p' est� contida no arquivo 'arq'. Pressup�e que 'p' pertence ao Conjunto.
        bool pertenceArquivo(string p, string arq);

        //Verifica se o Conjunto est� vaio.
        bool vazio();

        //Retorna a quantidade de elementos que existem no Conjunto.
        int cardinalidade();
};

#endif // CONJUNTO_INDICE_H
