/*Nome dell’esercizio: tab_mult
File attesi: tab_mult.c
Funzioni permesse: write

Scrivi un programma che visualizza la tabellina di un numero.

Il parametro sarà sempre un numero strettamente positivo che rientra nel tipo int,
e anche il risultato di quel numero moltiplicato per 9 rientrerà in un int.

Se non viene passato alcun parametro, il programma visualizza solo una nuova riga (\n).

Esempi:

$> ./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81

$> ./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171

$> ./tab_mult | cat -e
$*/

void    ft_putnbr(int num)
{
    char c;

    if (num < 0)
    {
        write(1, "-", 1);
        num *= -1;
    }
    else if (num >= 10)
        ft_putnbr(num / 10);
    else
    {
        c = (num % 10) + '0';
        write(1, &c, 1);
    }
}

int ft_atoi(char *str)
{
    int     n;
    int     s;

    n = 0;
    s = 1;

    while (*str == ' ' || *str >= 8 && *str <= 13)
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

void    ft_tab_mult(int num)
{
    int     i;

    i = 0;
    while (i <= 9)
    {
        ft_putnbr(i);
        write(1, "x", 1);
        ft_putnbr(num);

        write(1, "=", 1);
        ft_putnbr(i * num);
        write(1, "\n", 1);
        i++;
    }
}

int main (int ac, char **av)
{
    int num;

    if (ac == 2)
    {
        num = ft_atoi(num);
        ft_tab_mult(num);
    }
    else
        write(1, "\n", 1);
    return(0);
}