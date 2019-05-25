#include "Conjunto_Indice.h"

#include "Conjunto.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

 struct NO{
    struct NO* esquerda_;
    string palavra_;
    Conjunto arquivos_;
    struct NO* direita_;
};

Conjunto_Indice::Conjunto_Indice(){
    //ctor
    cardinalidade_ = 0;
    fim_ = new NO;
    fim_->direita_ = fim_;
    fim_->esquerda_ = fim_;
}

Conjunto_Indice::~Conjunto_Indice(){
    //dtor
    while(!vazio()){
        remover(menor());
    }
    delete fim_;

}

void Conjunto_Indice:: inserir(string p, string arq){
    if(!pertence(p)){
        NO* i = fim_->direita_;
        if(!vazio()){
            while(i != fim_ && i->palavra_ < p){
                i = i->direita_;
            }
        }
        NO* j = new NO;
        j->palavra_ = p;
        j->arquivos_.inserir(arq);
        //Ajustar o valor dos ponteiros do novo nó
        j->esquerda_ = i->esquerda_;
        j->direita_ = i;
        //Ajustar o valor dos ponteiros dos nós adjacentes ao novo nó.
        j->esquerda_->direita_ = j;
        j->direita_->esquerda_ = j;

        cardinalidade_ = cardinalidade_ + 1;
    }
    else{
        NO* i = fim_->direita_;
        while(i != fim_ && i->palavra_ != p){
            i = i->direita_;
        }
        i->arquivos_.inserir(arq);
    }
}

void Conjunto_Indice:: remover (string p){
    if(pertence(p)){
        NO* i = fim_->direita_;
        // Encontrar a posição de p.
        while(i->palavra_ != p){
            i = i->direita_;
        }
        i->direita_->esquerda_ = i->esquerda_;
        i->esquerda_->direita_ = i->direita_;
        delete i;
        cardinalidade_ = cardinalidade_ - 1;
    }
}

bool Conjunto_Indice:: pertence(string p){
    bool pertence_ = false;
    if(!vazio()){
        NO* i = fim_->direita_;
        // Percorrer o conjunto até encontrar p ou até o último elemento do conjunto.
        while(pertence_ == false && i != fim_){
            if(i->palavra_ == p){
                pertence_ = true;
            }
            i = i->direita_;
        }
    }
    return pertence_;
}

bool Conjunto_Indice::pertenceArquivo(string p, string arq){
    NO* i = fim_->direita_;
    // Encontrar a posição de p.
    while(i->palavra_ != p){
        i = i->direita_;
    }
    if(i->arquivos_.pertence(arq)){
        return true;
    }
    else{
        return false;
    }
}

bool Conjunto_Indice:: operator== (Conjunto_Indice& x){
    if (cardinalidade_ == x.cardinalidade_){
        bool igual_ = true;
        NO* i = fim_->direita_;
        // Percorrer o conjunto até não encontrar algum elemento ou até o último elemento do conjunto.
        while(igual_ == true && i != fim_){
            igual_ = x.pertence(i->palavra_);
            i = i->direita_;
        }
        return igual_;
    }
    else{
        return false;
    }
}

string Conjunto_Indice:: menor(){
    NO* i = fim_->direita_;
    string menor_ = i->palavra_;
    while(i != fim_){
        if(i->palavra_ < menor_){
            menor_ = i->palavra_;
        }
        i = i->direita_;
    }
    return menor_;
}

bool Conjunto_Indice::vazio(){
    if(fim_->direita_ == fim_ && fim_->esquerda_ == fim_){
        return true;
    }
    else{
        return false;
    }
}

int Conjunto_Indice:: cardinalidade(){
    return cardinalidade_;
}
