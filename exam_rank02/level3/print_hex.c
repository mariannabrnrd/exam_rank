/*Nome dell’esercizio: print_hex
File attesi: print_hex.c
Funzioni permesse: write

Scrivi un programma che prende un numero positivo (o zero) espresso in base 10,
e lo visualizza in base 16 (esadecimale) usando lettere minuscole,
seguito da una nuova riga.

Se il numero di parametri non è esattamente 1, il programma visualizza solo una nuova riga.

Esempi:
$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int n;
    int s;

    n = 0;
    s = 1;
    while (*str == ' ' || (*str >= 8 && *str <= 13))
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            s *= -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        n = (n * 10) + (*str - '0');
        str++;
    }
    return (n * s);
}

void    ft_puthex(int num)
{
    if (num == 0)
        write(1, "0", 1);
    else if (num >= 16)
    {
        ft_puthex(num/16);
        ft_puthex(num%16);
    }
    else
    {
        if (num <= 9)
            ft_putchar(num + '0');
        else
            ft_putchar(num - 10 + 'a');
    }
}

int main(int ac, char **av)
{
    int num;

    if (ac == 2)
    {
        num = ft_atoi(av[1]);
        ft_puthex(num);
    }
    else
        write(1, "\n", 1);
}