#include "semaphoresOO.h"

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

semaphoresOO::semaphoresOO(string name)
{
    //adiciona o nome ao semáforo
    if(name[0] == '/'){
        this->namesemaphore = name;

    }else{
        this->namesemaphore = "/";
        this->namesemaphore+=name;
    }
}

semaphoresOO::~semaphoresOO(){}

int semaphoresOO::clear(){
    //deleta semáforo
    return sem_unlink(this->namesemaphore.c_str());
}
int semaphoresOO::open(int valueStart, bool isNew){
    //se é um semáforo novo, tenta deletar o semáforo com o nome criado caso exista
    //caso seja apenas um carregamento de semáforo, ignora
    if(isNew){
        clear();
    }
    //tenta carregar o semáforo, caso consiga, retorna 1
    semaphore = sem_open( this->namesemaphore.c_str(),O_CREAT,0644,valueStart);
    if (semaphore == SEM_FAILED) {
        clear();
        return -1;
    }
    return 1;
}
//análogo ao post
int semaphoresOO::up(){
    return sem_post(this->semaphore);
}
//análogo ao wait
int semaphoresOO::down(){
    return sem_wait(this->semaphore);
}
//retorna o valor do semáforo
int semaphoresOO::value(){
    int returnedValue;
    sem_getvalue(this->semaphore,&returnedValue);
    return returnedValue;
}
