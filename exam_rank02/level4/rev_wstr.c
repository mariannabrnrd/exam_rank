/*Nome dell'esercizio: rev_wstr
File attesi: rev_wstr.c
Funzioni permesse: write, malloc, free

Scrivete un programma che riceva una stringa come parametro e stampi le 
sue parole in ordine inverso. Una "parola" è una parte della stringa 
delimitata da spazi e/o tabulazioni, oppure dall'inizio/fine della stringa.
Se il numero di parametri è diverso da 1, il programma deve stampare solo 
una nuova riga. Nei parametri che verranno testati, non ci saranno 
spazi "extra" (significa che non ci saranno spazi all'inizio o alla fine della stringa, 
e le parole saranno sempre separate da un solo spazio).

esempi:
$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e  
l'indifference de celui precede mepris du temps le$  
$> ./rev_wstr "abcdefghijklm"  
abcdefghijklm  
$> ./rev_wstr "il contempla le mont" | cat -e  
mont le contempla il$  
$> ./rev_wstr | cat -e  
$  
$>*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void rev_wstr(char *str)
{
    int temp;
    int start;
    int end;
    int i;

    i = 0;
    while (str[i])
        i++;
    while (i <= 0)
    {
        while (str[i] == ' ' || str[i] == '\t')
            i--;
        end = i;
        while (str[i] && (str[i] != ' ' || str[i] != '\t'))
            i--;
        start = i + 1;
        temp = start;
        while (start <= end)
        {
            write(1, &str[start], 1);
            start ++;
        }
        if (temp != 0)
            write(1, " ", 1);
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        rev_wstr(av[1]);
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}