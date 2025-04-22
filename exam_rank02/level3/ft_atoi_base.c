/*Nome dell’esercizio: ft_atoi_base
File attesi: ft_atoi_base.c
Funzioni permesse: Nessuna

Scrivi una funzione che converte una stringa str, espressa in base N (dove N <= 16),
in un numero intero in base 10, e lo restituisce.

I caratteri validi in ingresso sono:
0123456789abcdef

Ovviamente, questi caratteri devono essere limitati in base alla base specificata.
Ad esempio:

per base 4: i caratteri validi sono "0123"

per base 16: "0123456789abcdef"

Le lettere maiuscole devono essere anch'esse riconosciute:
Ad esempio, "12fdb3" deve essere trattato come equivalente a "12FDB3".

I segni meno (-) devono essere interpretati solo se compaiono come primo carattere della stringa.

La tua funzione deve essere dichiarata così:
int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int num;
    int sign;
    int digit;

    num = 0;
    sign = 1;
    digit = 0;

    if (str_base < 2 || str_base > 16)
        return (0);
    while (*str == ' ' || (*str >= 8 && *str <= 13))
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= - 1;
        str++;
    }
    while (*str)
    {
        digit = ft_isdigit(*str);
        if (digit < 0 || digit >= str_base)
            return (0);
        if (digit >= 0 && digit < str_base)
            num = (num * str_base) + digit;
        str++;
    }
    return (num * sign);
}

/* MAIN ************************************************************************************************** */
int main ()
{
    int num;
    char *str;
    int base;

    str = "h1a";
    base = 16;
    num = ft_atoi_base(str, base);
    printf("numero: %d in base %d\n", num, base);
    return(0);
}