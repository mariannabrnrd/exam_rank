/* Nome dell'esercizio: fprime
File richiesti: fprime.c
Funzioni permesse: printf, atoi

Scrivi un programma che accetta un valore int positivo e visualizza i suoi fattori primi
sull'output standard, seguito da una nuova riga.

I fattori devono essere mostrati in ordine crescente e separati dal carattere *,
in modo che l'espressione nell'output dia il risultato corretto.

Se il numero di argomenti non è uguale a 1, stampa semplicemente una nuova riga.

L'input, quando fornito, sarà valido.

esempi:

$> ./fprime 225225 | cat -e  
3*3*5*5*7*11*13$  
$> ./fprime 8333325 | cat -e  
3*3*5*5*7*11*13*37$  
$> ./fprime 9539 | cat -e  
9539$  
$> ./fprime 804577 | cat -e  
804577$  
$> ./fprime 42 | cat -e  
2*3*7$  
$> ./fprime 1 | cat -e  
1$  
$> ./fprime | cat -e  
$  
$> ./fprime 42 21 | cat -e  
$  
$>*/

#include <unistd.h>
#include <stdlib.h>

void ft_putnbr(int num)
{
    char c;

    if (num < 0)
    {
        write(1, "-", 1);
        num *= -1;
    }
    else if (num >= 10)
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

void fprime (int num)
{
    int i;

    i = 2;

    if (num == 1)
    {
        write(1, "1", 1);
    }
    else
    {
        while (i <= num)
        {
            if (num % i == 0)
            {
                ft_putnbr(i);
                num /= i;
                if (num != 1)
                    write(1, "*", 1);
                i = 1; 
            }
            i++;
        }
    }

}

int main(int ac, char **av)
{
    int num;

    if (ac == 2)
    {
        num = atoi(av[1]);
        if (num > 0)
        {
            fprime(num);
            write(1, "\n", 1);
        }
        else
        {
            write(1, "\n", 1);
            return(0);
        } 
    }
    else
        write(1, "\n", 1);
    return(0);
}