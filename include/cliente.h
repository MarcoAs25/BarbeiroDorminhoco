#ifndef CLIENTE_H
#define CLIENTE_H

#include <semaphoresOO.h>
#include <unistd.h>
#include <ctime>

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


class cliente
{
    public:
        cliente();
        virtual ~cliente();
        void vidaCliente(int id);
        void chegou(int id);
        void foiembora(int id);
        void entrou(int id);
        void sentouNaCadeiraDeEspera(int id);
        void cabelocortado(int id);
};

#endif // CLIENTE_H
