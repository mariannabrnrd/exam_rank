/*Nome dell'esercizio: ft_list_size
File richiesti: ft_list_size.c, ft_list.h
Funzioni permesse: (nessuna)

Scrivi una funzione che restituisca il numero di elementi in una lista collegata (linked list) che le viene passata.

La funzione deve essere dichiarata nel seguente modo:

int	ft_list_size(t_list *begin_list);

Devi utilizzare la seguente struttura e inserirla in un file chiamato ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

//nel file "ft_list.h"

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

// ********************************************************************************************************************* //

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int size;

    size = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        size++;
    }
    return (size);
}
