/*Nome dell’esercizio: ft_list_foreach
File richiesti: ft_list_foreach.c, ft_list.h
Funzioni permesse: (nessuna)

Scrivere una funzione che riceve una lista e un puntatore a funzione, 
e applica questa funzione a ogni elemento della lista.

La funzione deve essere dichiarata nel seguente modo:
void ft_list_foreach(t_list *begin_list, void (*f)(void *));

La funzione puntata da f verrà usata nel seguente modo:
(*f)(list_ptr->data);

Devi usare la seguente struttura, da inserire nel file ft_list.h:
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}