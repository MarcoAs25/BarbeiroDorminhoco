#ifndef BARBEIRO_H
#define BARBEIRO_H
#include <iostream>
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


using namespace std;
class barbeiro
{
    public:
        barbeiro();
        virtual ~barbeiro();
        void vidaBarbeiro();
    private:
        void dormir();
        void cortar();
        void atender();
        void proximo();
};

#endif // BARBEIRO_H
