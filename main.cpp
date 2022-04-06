#include <iostream>
#include <barbearia.h>

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

int main()
{
    barbearia bar;
    setlocale(LC_ALL,"portuguese");
    bar.abrirBarbearia();
    return 0;
}


