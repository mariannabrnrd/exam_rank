/*Nome dell’esercizio: ft_rrange
File richiesti: ft_rrange.c
Funzioni permesse: malloc

Scrivi la seguente funzione:
int *ft_rrange(int start, int end);

La funzione deve allocare (usando malloc()) un array di interi, 
riempirlo con valori consecutivi partendo da end e arrivando 
fino a start (inclusi sia start che end), e poi restituire un 
puntatore al primo elemento dell’array.

Esempi:
-Chiamando ft_rrange(1, 3), la funzione restituirà un array contenente: 3, 2, 1
-Chiamando ft_rrange(-1, 2), restituirà: 2, 1, 0, -1
-Chiamando ft_rrange(0, 0), restituirà: 0
-Chiamando ft_rrange(0, -3), restituirà: -3, -2, -1, 0
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int *rrange;
    int i;

    if (start > end)
        i = (start - end) + 1;
    else
        i = (end - start) + 1;
    rrange = (int *)malloc(sizeof(int) * i);
    if (!rrange)
        return (NULL);
    while (i)
    {
        i--;
        rrange[i] = start;
        start += 1;
    }
    return (rrange);
}

int		main(void)
{
    int start;
    int end;
    int *result;
    int i;

    i = 0;
    start = -1;
    end = 2;
    result = ft_rrange(start, end);
    printf("ft_rrange(%d, %d): ",start, end);
    while (i <= end - start)
    {
        printf("%d, ", result[i]);
        i++;
    }
    write(1, "\n", 1);
    free(result);
    return (0);
}