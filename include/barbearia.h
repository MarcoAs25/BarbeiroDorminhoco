#ifndef BARBEARIA_H
#define BARBEARIA_H

#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <semaphoresOO.h>
#include <cliente.h>
#include <barbeiro.h>
#include <csignal>
#include <sys/types.h>

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

class barbearia
{
    public:
        barbearia();
        virtual ~barbearia();
        void abrirBarbearia();
        static void fecharBarbearia(int signal);
    private:
        vector<thread> clientesThreads;
        vector<cliente> clientes;
        const int nClientes = 15;
        barbeiro barbeirobj;

};

#endif // BARBEARIA_H
