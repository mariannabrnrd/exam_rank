/*Nome dell’esercizio: sort_int_tab
File richiesti: sort_int_tab.c
Funzioni permesse: (nessuna)

Scrivi la seguente funzione:
void sort_int_tab(int *tab, unsigned int size);

La funzione deve ordinare in loco (cioè senza usare array aggiuntivi) 
l’array di interi tab, che contiene esattamente size elementi, in 
ordine crescente.
I duplicati devono essere mantenuti.
L’input sarà sempre valido e coerente.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    sort_int_tab(int *tab, unsigned int size)
{
    unsigned int    i;
    int             temp;

    i = 0;
    temp = 0;
    //ciclo lo stack di numeri tramite i (size = numeri totali)
    while (i < size - 1)
    {
        //se num è maggiore del suo successivo
        if (tab[i] > tab[i + 1])
        {
            //swap
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            //ripartiamo da 0
            i = 0;
        }
        //incrementiamo
        else
            i++;
    }
}

/* -----------------main per testare--------------------------- */

int     main()
{
    int     i = 0;
    int     size = 6;
    int     tab[] = {4, 2, 8, 6, 1, 3};

    sort_int_tab(tab, size);
    printf("stack di numeri ordinati: \n");
    while (i < size)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    printf("\n");
    return(0);
}
