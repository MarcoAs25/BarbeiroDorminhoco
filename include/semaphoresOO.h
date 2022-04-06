#ifndef SEMAPHORESOO_H
#define SEMAPHORESOO_H

#include <semaphore.h>
#include <fcntl.h>
#include <iostream>

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
class semaphoresOO
{
    public:
        semaphoresOO(string name);
        virtual ~semaphoresOO();
        int clear();
        int open(int valueStart, bool isNew);
        int up();
        int down();
        int value();
    private:
        sem_t *semaphore;
        string namesemaphore;
};

#endif // SEMAPHORESOO_H
