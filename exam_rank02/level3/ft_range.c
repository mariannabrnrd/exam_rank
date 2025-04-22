/*Nome dell'assegnazione: ft_range
File attesi: ft_range.c
Funzioni permesse: malloc

Scrivi la seguente funzione:
int *ft_range(int start, int end);

Essa deve allocare (usando malloc()) un array di numeri interi,
riempirlo con valori consecutivi che iniziano da start e terminano 
in end (inclusi sia start che end!), e poi restituire un puntatore 
al primo valore dell'array.

esempi:
Con i parametri (1, 3), restituirà un array contenente 1, 2, 3.
Con (-1, 2), restituirà un array contenente -1, 0, 1, 2.
Con (0, 0), restituirà un array contenente 0.
Con (0, -3), restituirà un array contenente 0, -1, -2, -3.*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *range;
    int size;

    if (start > end)
        size = (start - end) + 1;
    else
        size = (end - start) + 1;
    range = (int *)malloc(sizeof(int) * size);
    if (!range)
        return(0);
    while (size)
    {
        size--;
        range[size] = end;
        if (start > end)
            end += 1;
        else
            end -= 1;
    }
    return (range);
}

int		main(void)
{
    int start;
    int end;
    int *result;
    int i;
    int size;

    i = 0;
    start = 0;
    end = 0;
    if (start > end)
        size = (start - end) + 1;
    else
        size = (end - start) + 1;
    result = ft_range(start, end);
    printf("ft_rrange(%d, %d): \n",start, end);
    while (i < size)
    {
        printf("%d, ", result[i]);
        i++;
    }
    write(1, "\n", 1);
    free(result);
    return (0);
}