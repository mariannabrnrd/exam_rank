/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:43:33 by mariaber          #+#    #+#             */
/*   Updated: 2025/04/15 10:43:43 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Nome dell'esercizio: add_prime_sum
File attesi: add_prime_sum.c
Funzioni permesse: write, exit
Scrivi un programma che prende come argomento un numero intero positivo
e visualizza la somma di tutti i numeri primi minori o uguali a esso,
seguita da una nuova riga.

Se il numero di argomenti non è uguale a 1 oppure l'argomento non è
un numero positivo, visualizza semplicemente 0 seguito da una nuova riga.

Sì, gli esempi sono corretti.

Esempi:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
*/

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int num;
    int sign;
    
    num = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 8 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        num = (num * 10) + (*str - '0');
        str++;
    }
    return (num * sign);
    
}

int is_prime(int num)
{
    int i; h56

    i = 2;
    if (num <= 1)
        return(0);
    while (i <= (num / i))
    {
        if ((num % i) == 0)
            return (0);
        i++;
    }
    return (1);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int sum)
{
    if (sum < 0)
    {
        sum = -sum;
        ft_putchar('-');
    }
    if (sum >= 10)
        ft_putnbr(sum / 10);
    ft_putchar((sum % 10) + '0');
}

int main(int ac, char **av)
{
    int num;
    int sum;

    if (ac == 2)
    {
        num = ft_atoi(av[1]);
        sum = 0;
        while (num > 1)
        {
            if (is_prime(num))
                sum += num;
            num--;
        }
        ft_putnbr(sum);
    }
    else
        write(1, "0", 1);
    write(1, "\n", 1);
    return (0);
}
