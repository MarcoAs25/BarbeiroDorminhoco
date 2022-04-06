#include "cliente.h"

/********************************************************
 * main.cpp - barber sleeping problem                   *
 *                                                      *
 * Author:  Marco Antônio. 2022                         *
 * RA: 0040396                                          *
 * Author:  Kevenn Henrique. 2022                       *
 * RA: 0016056                                          *
 * Purpose: study of inter-process communication and    *
 * synchronization problem.                             *
 *                                                      *
 * Obs:This code is part of one of the final works of   *
 * the Operating Systems                                *
 ********************************************************/

cliente::cliente(){}
cliente::~cliente(){}

void cliente::vidaCliente(int id){
    //mesma ideia de carregamento do barbeiro
    semaphoresOO semBarbeiro("/sem_barbeiro");
    semaphoresOO semCliente("/sem_cliente");
    semaphoresOO mutex("/sem_mutex");
    semaphoresOO cadeirasLivres("/sem_cadLivres");

    semBarbeiro.open(0,false);
    semCliente.open(0,false);
    mutex.open(1,false);
    cadeirasLivres.open(5,false);
    //cliente espera um tempo de acordo com seu id E rand, serve para que não cheguem todos ao mesmo tempo
    unsigned seed = time(0);
    srand(seed);
    unsigned int x = 1+rand()%150;
    usleep(x*id);
    this->chegou(id);
    //quando o cliente chega, verifica se já têm alguém verificando se têm cadeiras livres e aguarda sua vez de verificar
    mutex.down();
    //chegando sua vez, verifica se tem cadeiras livres, caso não tenha, ele sai da seção crítica
    if(cadeirasLivres.value()>0){
        //caso tenha conseguido entrar na barbearia, é printado na tela que entrou
        this->entrou(id);
        //senta na cadeira de espera
        cadeirasLivres.down();
        this->sentouNaCadeiraDeEspera(id);
        //entra na "fila" para o barbeiro cortar seu cabelo e libera para que outro possa verificar mais alguma outra cadeira livre
        semCliente.up();
        mutex.up();
        //espera o barbeiro ficar livre para cortarseu cabelo
        semBarbeiro.down();
        //apos o barbeiro cortar seu cabelo, é mostrado na tela
        this->cabelocortado(id);
    }else{
        mutex.up();
        this->foiembora(id);
    }
}


//Mesma lógica das funções do barbeiro onde apenas há um cout na seção crítica.

void cliente::chegou(int id){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O cliente com id: "<<id<<" Chegou!"<<endl;
    mutexprint.up();
}
void cliente::foiembora(int id){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O cliente com id: "<<id<<" Foi embora pois estava cheio!"<<endl;
    mutexprint.up();
}
void cliente::entrou(int id){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O cliente com id: "<<id<<" Entrou no salão!"<<endl;
    mutexprint.up();
}
void cliente::sentouNaCadeiraDeEspera(int id){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O cliente com id: "<<id<<" Sentou na cadeira de Espera!"<<endl;
    mutexprint.up();
}
void cliente::cabelocortado(int id){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O cliente com id: "<<id<<" Cortou o cabelo!"<<endl;
    mutexprint.up();
}
