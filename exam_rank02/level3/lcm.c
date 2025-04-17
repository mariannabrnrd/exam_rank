/*Nome dell’esercizio: lcm
File attesi: lcm.c
Funzioni permesse: (nessuna funzione standard specificata)

Scrivi una funzione che prende due unsigned int come parametri e restituisce
il minimo comune multiplo (LCM) calcolato a partire da questi parametri.

Il minimo comune multiplo (LCM - Lowest Common Multiple) di due numeri interi
non nulli è il più piccolo intero positivo divisibile da entrambi i numeri.

Il LCM può essere calcolato in due modi:

Calcolando tutti i multipli di ciascun numero fino a trovarne uno in comune (diverso da 0)

Oppure, usando il MCD (Massimo Comun Divisore o HCF - Highest Common Factor), con la formula:
            LCM(x, y) = |x * y| / HCF(x, y)
Se almeno uno dei due numeri è zero, allora il risultato del LCM sarà 0.
La tua funzione deve essere prototipata così:
unsigned int    lcm(unsigned int a, unsigned int b);*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    int     i;

    if (a == 0 || b == 0)
        return (0);
    if (a > b)
        i = a;
    else 
        i = b;
    while (1)
    {
        if (i % a == 0 && i % b == 0)
            return(i);
        i++;
    }
}