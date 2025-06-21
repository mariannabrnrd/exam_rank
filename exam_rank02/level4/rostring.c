/*Nome dell’esercizio: rostring
File richiesti: rostring.c
Funzioni permesse: write, malloc, free

Scrivi un programma che prenda una stringa e la 
stampi dopo averla ruotata di una parola a sinistra.
In altre parole, la prima parola diventa l’ultima, e 
tutte le altre restano nello stesso ordine.
Un "parola" è definita come una parte della stringa separata 
da spazi, tabulazioni, o l’inizio/fine della stringa.
Nell’output, le parole devono essere separate da un solo spazio.
Se non viene fornito alcun argomento, il programma deve stampare 
un a capo (\n).

esempi:
$> ./rostring "abc   " | cat -e
abc$
$>

$> ./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>

$> ./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>

$> ./rostring | cat -e
$
$>
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    rostring(char *str)
{
    int     space;
    int     start;
    int     end;
    int     i;

    i = 0;
    space = 0;
    //skippiamo gli spazi inziali
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    //controllino
    if (!str[i])
        return;
    //assegno start all'inizio della prima parola
    start = i;
    //scorro tutte le lettere
    while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
        i++;
    //assegno end alla fine della prima parola
    end = i;
    //scorro il resto della stringa
    while (str[i])
    {
        //se ci sono spazi li salto
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        // se il carattere dopo gli spazi esiste
        if (str[i])
        {
            //controllo se c'è uno spazio da scrivere
            if (space == 1)
                write(1, " ", 1);
            //setto il contatore space a 1
            space = 1;
            //scrivo finche non trovo uno spazio
            while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
                write(1, &str[i++], 1);
        }
    }
    //scrivo lo spazio prima dell'ultima parola
    if (space == 1)
        write(1, " ", 1);
    //scrivo la prima parola
    while (start < end)
        write(1, &str[start++], 1);

}

int     main(int ac, char **av)
{
    if (ac == 2)
    {
        rostring(av[1]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return(0);
}