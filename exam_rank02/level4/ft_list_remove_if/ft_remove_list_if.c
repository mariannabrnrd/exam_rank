/* Nome dell'esercizio: ft_list_remove_if
File richiesti: ft_list_remove_if.c
Funzioni permesse: free

Scrivere una funzione chiamata ft_list_remove_if che 
rimuove dalla lista passata come argomento ogni elemento 
i cui dati siano "uguali" ai dati di riferimento forniti.

Verrà dichiarata la seguente funzione:
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

Il parametro cmp è una funzione che prende due void * e 
restituisce 0 quando i due parametri sono considerati uguali.

Dovrai usare il file ft_list.h, che contiene:
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
*/

#include <stdlib.h>
#include "ft_list.h"

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list      *temp;
    t_list      *current;

    current = *begin_list;                  //creo una lista che punterà all'inzio della mia "lista" da controllare
    while (current && current->next)        //cicla finchè current esiste e finche non arriva al NULL
    {
        if ((*cmp)(current->next->data, data_ref) == 0)     //se la funzione riporta 0, dobbiamo rimuovere quel "blocco" dalla lista
        {
            temp = current->next;                           //assegno a temp il "blocco" da eliminare
            current->next = current->next->next;            //nel "blocco" che abbiamo eliminato, assegno il "blocco" successivo
            free(temp);                                     //libero temp
        }
        current = current->next;                            //scorro la lista
    }
    current = *begin_list;                  //riposiziono la lista all'inizio

    /*qui controlliamo il primo valore della lista, se riporta 0
    posiziono "*begin_list" al blocco successivo di current (modificato in precedenza)*/

    if (current && (*cmp)(current->data, data_ref) == 0)
    {
        *begin_list = current->next;                 
        free(current);
    }
}