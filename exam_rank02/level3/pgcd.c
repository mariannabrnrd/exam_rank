/*Nome dell’esercizio: pgcd
File attesi: pgcd.c
Funzioni permesse: printf, atoi, malloc, free

Scrivi un programma che prende due stringhe come argomenti,
ognuna rappresentante un numero intero strettamente positivo che rientra nel tipo int.

Considerando questi numeri come denominatori di due frazioni,
visualizza il loro massimo comune divisore (MCD), seguito da una nuova riga.
(Il risultato sarà sempre un numero intero strettamente positivo.)

Se il numero di argomenti non è esattamente 2, il programma deve stampare solo una nuova riga.

Esempi:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int ac, char **av)
{
    int     n1;
    int     n2;

    if (ac == 3)
    {
        n1 = atoi(av[1]);
        n2 = atoi(av[2]);

        if (n1 > 0 && n2 > 0)
        {
            while (n1 != n2)
            {
                if (n1 > n2)
                    n1 = n1 - n2;
                else
                    n2 = n2 - n1;
            }
            printf("%d\n", n1);
        }
    }
    else
        write(1, "\n", 1);
    return(0);
}
