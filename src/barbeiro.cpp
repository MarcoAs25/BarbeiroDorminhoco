#include "barbeiro.h"

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

barbeiro::barbeiro()
{
    //ctor
}

barbeiro::~barbeiro()
{
}

void barbeiro::vidaBarbeiro(){
    //cria instâncias do semáforo com seus nomes
    semaphoresOO semBarbeiro("/sem_barbeiro");
    semaphoresOO semCliente("/sem_cliente");
    semaphoresOO mutex("/sem_mutex");
    semaphoresOO cadeirasLivres("/sem_cadLivres");
    //carrega os valores dos semáforos para o objeto
    semBarbeiro.open(0,false);
    semCliente.open(0,false);
    mutex.open(1,false);
    cadeirasLivres.open(5,false);

    while(true){
        //se todas as cadeiras estão livres é mostrado na tela que o barbeiro está dormindo
        if(cadeirasLivres.value() == 5){
            this->dormir();
        }
        //barbeiro dorme na espera de um cliente
        semCliente.down();
        //quando é acordado, chama um cliente pra cadeira do barbeiro, caso algum cliente anterior ainda não
        //tenha levantado, espera o cliente levantar
        mutex.down();
        //após o cliente sentar na cadeira do barbeiro, a cadeira de espera onde o cliente estava sentada é liberada
        cadeirasLivres.up();
        //atende/corta o cabelo do cliente
        this->atender();
        this->cortar();
        //avisa que terminou
        semBarbeiro.up();
        //barbeiro libera sua cadeira
        mutex.up();
        //avisa que terminou
        this->proximo();
    }
}


//O funcionamento das funções abaixo são semelhantes
//primeiro é carregado o semáforo de print
//tenta entrar na seção crítica e quando entra, executa o cout
//após a execução do cout, sai da seção crítica.

void barbeiro::dormir(){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O barbeiro está dormindo"<<endl;
    mutexprint.up();
}

void barbeiro::cortar(){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O barbeiro está cortando o cabelo do cliente"<<endl;
    mutexprint.up();
    //este é o tempo no qual o corte leva para ser feito
    unsigned seed = time(0);
    srand(seed);
    unsigned int x = 1+rand()%130;
    usleep(x);
}

void barbeiro::atender(){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O barbeiro está atendendo o cliente"<<endl;
    mutexprint.up();
}

void barbeiro::proximo(){
    semaphoresOO mutexprint("/sem_mutexprint");
    mutexprint.open(1,false);
    mutexprint.down();
    cout<<"O barbeiro terminou de atender o cliente"<<endl;
    mutexprint.up();
}

