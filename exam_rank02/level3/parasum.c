/*Nome dell'assegnazione: paramsum
File attesi: paramsum.c
Funzioni permesse: write

Scrivi un programma che visualizzi il numero di 
argomenti passati ad esso, seguito da un carattere 
di nuova riga.Se non vengono passati argomenti, 
visualizza semplicemente 0 seguito da una nuova riga.

esempi:
$> ./paramsum 1 2 3 5 7 24
6
$> ./paramsum 6 12 24 | cat -e
3$
$> ./paramsum | cat -e
0$*/

#include <unistd.h>

void ft_putnbr(int num)
{
    char c;

    if (num < 0)
    {
        num *= -1;
        write(1, "-1", 1);
    }
    if (num >= 10)
    {
        ft_putnbr(num / 10);
        ft_putnbr(num % 10);
    }
    else
    {
        c = num + '0';
        write(1, &c, 1);
    }
}

int main(int ac, char **av)
{
    ft_putnbr(ac - 1);
    write(1, "\n", 1);
}