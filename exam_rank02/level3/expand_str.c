/*Nome dell’esercizio: expand_str
File attesi: expand_str.c
Funzioni permesse: write

Scrivi un programma che prende una stringa e la visualizza con esattamente tre spazi
tra ogni parola, senza spazi o tabulazioni all'inizio o alla fine,
seguita da una nuova riga.

Una parola è una parte della stringa separata da spazi/tabulazioni
o dall'inizio/fine della stringa.

Se il numero di argomenti non è esattamente 1, oppure non ci sono parole,
il programma visualizza solo una nuova riga.

Esempi:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i;
    int space;

    i = 0;
    space = 0;
    if (ac == 2)
    {
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i])
        {
            if (av[1][i] == ' ' || av[1][i] == '\t')
                space = 1;
            if (!(av[1][i] == ' ' || av[1][i] == '\t'))
            {
                if (space == 1)
                {
                    write(1, "   ", 3);
                    space = 0;
                }
                write(1, &av[1][i], 1);
            }
            i++;
            
        }
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return(0);
}