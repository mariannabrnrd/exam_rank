/*Nome dell’esercizio: hidenp
File attesi: hidenp.c
Funzioni permesse: write

Scrivi un programma chiamato hidenp che prende due stringhe come argomenti
e visualizza 1 seguito da una nuova riga, se la prima stringa è nascosta nella seconda,
altrimenti visualizza 0 seguito da una nuova riga.

Siano s1 e s2 le due stringhe.
Diciamo che s1 è nascosta in s2 se è possibile trovare ogni carattere di s1 dentro s2,
nell’ordine in cui appaiono in s1 (non necessariamente consecutivi).

Anche una stringa vuota è considerata nascosta in qualsiasi altra stringa.

Se il numero di argomenti non è esattamente 2, il programma visualizza solo una nuova riga.

Esempi:

$> ./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$> ./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$> ./hidenp "abc" "btarc" | cat -e
0$
$> ./hidenp | cat -e
$*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int ac, char **av)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (ac == 3)
    {
        while (av[1][i] && av[2][j])
        {
            if (av[1][i] == av[2][j])
                i++;
            j++;
        }
        if (av[1][i] == '\0')
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return (0);
}
