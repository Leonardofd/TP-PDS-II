/*
Máquina de Busca
Programação e Desenvolvimento de Software II

Leonardo Felipe 
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Conjunto.h"
#include "Conjunto.cpp"
#include "Conjunto_Indice.h"
#include "Conjunto_Indice.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

void tratar_letras_maiusculas(char &c);

void indice_invertido(ifstream& arq, Conjunto_Indice& t, string nomeArquivo);

int main(int argc,char *argv[]){
    ifstream arquivo;
    Conjunto_Indice palavras;

    for(int i = 1; i < argc; i++){
        arquivo.open(argv[i]);
        if(!arquivo.is_open()){
            cout << "Erro ao abrir o arquivo " << argv[i];
            return(1);
        }
        indice_invertido(arquivo, palavras, argv[i]);
        arquivo.close();
    }

    char fim = 'S';
    while(fim == 'S' || fim == 's'){
    cout << endl << "Digite o que deseja pesquisar: ";
    string p;
    cin >> p;
    for(int i = 0; i < p.size(); i++){
        tratar_letras_maiusculas(p[i]);
    }
    if(palavras.pertence(p)){
        for(int i = 0; i < argc; i++){
            if(palavras.pertenceArquivo(p,argv[i])){
                cout << argv[i] << endl;
            }
        }
    }
    else{
        cout << endl << "Palavra nao encontrada." << endl;
    }
    cout << endl << "Deseja fazer outra pesquisa? (S)IM     (N)AO    ";
    cin >> fim;
    }

    return 0;
}

void tratar_letras_maiusculas(char &c){
    if(c >= 'A' && c <= 'Z'){
        c = c - 'A';
        c = c + 'a';
    }
}

void indice_invertido(ifstream& arq, Conjunto_Indice& t, string nomeArquivo){
    char C;
    string palavra;
    while (arq.get(C)){
        if((C >= 'a' && C <= 'z')||(C >= 'A' && C <= 'Z')){
            tratar_letras_maiusculas(C);
            palavra = palavra + C;
        }
        else if(palavra != ""){
            t.inserir(palavra, nomeArquivo);
            palavra = "";
        }
    }
}
