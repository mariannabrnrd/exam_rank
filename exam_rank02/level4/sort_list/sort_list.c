/*Nome dell’esercizio: sort_list
File richiesti: sort_list.c
Funzioni permesse: (nessuna)

Scrivi la seguente funzione:
t_list *sort_list(t_list* lst, int (*cmp)(int, int));

Questa funzione deve ordinare la lista fornita come parametro, 
utilizzando il puntatore a funzione cmp per determinare l’ordine 
da applicare, e deve restituire un puntatore al primo elemento 
della lista ordinata.

I duplicati devono essere mantenuti.

I dati in input saranno sempre coerenti 
(cioè la lista è ben formata, non contiene loop o errori strutturali).

Devi usare il tipo t_list descritto nel file list.h fornito.
Devi includere questo file con #include "list.h", ma non devi 
implementarlo tu stesso: utilizzeremo il nostro file list.h durante la 
compilazione del tuo codice.

Le funzioni passate come cmp restituiranno sempre un valore diverso 
da 0 se a e b sono nell’ordine corretto, e 0 altrimenti.
Ad esempio, la seguente funzione cmp ordina la lista in ordine crescente:

int ascending(int a, int b)
{
    return (a <= b);
)
Struttura t_list (fornita nel file list.h):
typedef struct s_list t_list;

struct s_list
{
    int     data;
    t_list  *next;
);
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list      *start;
    int         temp;

    start = lst;        //start punterà all'inizio della lista
    while (lst->next)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            temp = lst->data;                   //swappiamo i valori
            lst->data = lst->next->data;
            lst->next->data = temp;
            lst = start;                        //ripartiamo dall'inizio
        }
        else
            lst = lst->next;                    //passiamo al successivo
    }
    return (start);                             //riportiamo start che punta alla lista modificata
}
