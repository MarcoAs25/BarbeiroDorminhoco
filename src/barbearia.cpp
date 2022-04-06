#include "barbearia.h"

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

barbearia::barbearia()
{
    //associa a função para o término da funçãoa
    signal(SIGINT,barbearia::fecharBarbearia);
    //cria os semáforos utilizados
    semaphoresOO semBarbeiro("/sem_barbeiro");
    semaphoresOO semCliente("/sem_cliente");
    semaphoresOO mutex("/sem_mutex");
    semaphoresOO cadeirasLivres("/sem_cadLivres");
    semaphoresOO mutexprint("/sem_mutexprint");
    //inicia os semáforos utilizados, (True para criar um novo e False para carregar um semáforo existente)
    mutexprint.open(1,true);
    semBarbeiro.open(0,true);
    semCliente.open(0,true);
    mutex.open(1,true);
    cadeirasLivres.open(5, true);
    //cria os clientes
    clientes.resize(15);
}

barbearia::~barbearia()
{
}
void barbearia::fecharBarbearia(int signal){
    //termina o programa chamando o sigterm
    cout<<"\nBarbearia fechada! O barbeiro foi embora"<<endl;
    exit(0);
}

void barbearia::abrirBarbearia(){
    //instancia as threads do cliente e barbeiro
    clientesThreads.push_back(thread(&barbeiro::vidaBarbeiro,&barbeirobj));
    for(int i = 1; i <= nClientes; i++){
        clientesThreads.push_back(thread(&cliente::vidaCliente,clientes[i-1], i-1));
    }
    //faz a sincronização das threads
    for(int i = 0; i <= nClientes; i++){
        clientesThreads[i].join();
    }
}
