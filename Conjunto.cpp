#include "Conjunto.h"

#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

typedef struct no{
    struct no* esquerda_;
    string palavra_;
    struct no* direita_;
}no;

Conjunto::Conjunto(){
    //ctor
    cardinalidade_ = 0;
    fim_ = new no;
    fim_->direita_ = fim_;
    fim_->esquerda_ = fim_;
}

Conjunto::~Conjunto(){
    //dtor
    while(!vazio()){
        remover(menor());
    }
    delete fim_;
}

void Conjunto:: inserir(string p){
    if(!pertence(p)){
        no* i = fim_->direita_;
        if(!vazio()){
            while(i != fim_ && i->palavra_ < p){
                i = i->direita_;
            }
        }
        no* j = new no;
        j->palavra_ = p;
        //Ajustar o valor dos ponteiros do novo nó.
        j->esquerda_ = i->esquerda_;
        j->direita_ = i;
        //Ajustar o valor dos ponteiros dos nós adjacentes ao novo nó
        j->esquerda_->direita_ = j;
        j->direita_->esquerda_ = j;

        cardinalidade_ = cardinalidade_ + 1;
    }
}

void Conjunto:: remover (string p){
    if(pertence(p)){
        no* i = fim_->direita_;
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

bool Conjunto:: pertence(string p){
    bool pertence_ = false;
    if(!vazio()){
        no* i = fim_->direita_;
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

bool Conjunto:: operator== (Conjunto& x){
    if (cardinalidade_ == x.cardinalidade_){
        bool igual_ = true;
        no* i = fim_->direita_;
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

void Conjunto:: operator= (Conjunto& x){
    while(!vazio()){
        remover(menor());
    }
    no* i;
    for(i = x.fim_->direita_; i != x.fim_; i = i->direita_){
        inserir(i->palavra_);
    }
}



string Conjunto:: menor(){
    no* i = fim_->direita_;
    string menor_ = i->palavra_;
    while(i != fim_){
        if(i->palavra_ < menor_){
            menor_ = i->palavra_;
        }
        i = i->direita_;
    }
    return menor_;
}

bool Conjunto::vazio(){
    if(fim_->direita_ == fim_ && fim_->esquerda_ == fim_){
        return true;
    }
    else{
        return false;
    }
}

int Conjunto:: cardinalidade(){
    return cardinalidade_;
}
