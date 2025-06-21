/*Nome dell’esercizio: flood_fill
File richiesti: *.c, *.h
Funzioni permesse: nessuna

Scrivere una funzione che accetti un 'char **' come matrice bidimensionale 
di caratteri, un parametro size di tipo t_point come dimensione della matrice,
e un parametro begin di tipo t_point come punto di partenza.

A partire dal punto begin, la funzione deve riempire tutta l’area sostituendo i 
caratteri con il carattere 'F'. L’area è definita come un insieme di caratteri 
uguali e adiacenti orizzontalmente o verticalmente, delimitati da caratteri 
diversi o dai bordi della matrice.

⚠️ La funzione non deve riempire in diagonale.

La funzione flood_fill deve essere dichiarata come segue:
void flood_fill(char **tab, t_point size, t_point begin);

La struttura t_point deve essere dichiarata nel modo seguente:
typedef struct  s_point
{
    int x;
    int y;
} t_point;
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "flood_fill.h"

void    fill(char **tab, t_point size, t_point cur, char to_fill)
{
    if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y || tab[cur.y][cur.x] != to_fill)
        return;
    
    tab[cur.y][cur.x] = 'F';
    
    fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
    fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
    fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
    fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
}

void    flood_fill(char **tab, t_point size, t_point begin)         //tab conterrà la nostra matrice
{                                                                   //size avrà le misure complete di x-y
    fill(tab, size, begin, tab[begin.y][begin.x]);                  //begin avrà la posizione del carattere da "riempire"
}                                                                   //in fill() passiamo:
                                                                    //la matrice (da modificare)
                                                                    //le misure complete di x-y
                                                                    //begin che dovremo spostare tramite la ricorsiva
                                                                    //tab[][] sarà il carattere da "sostituire" (serve per verificare quando si incontra 1 o quando 0)
/* ----------------main per testare------------------------------ */

char    **make_area(char **zone, t_point size)
{
    char    **new;
    int     i;
    int     j;

    i = 0;
    new = malloc(sizeof(char *) * size.y);
    while (i < size.y)
    {
        j = 0;
        new[i] = malloc(size.x + 1);
        while (j < size.x)
        {
            new[i][j] = zone[i][j];
            j++;
        }
        new[i][size.x] = '\0';
        i++;
    }
    return (new);
}

int main(void)
{
    int         i;
    char        **area;
    char        *zone[] ={
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
    };
    t_point     size = {8, 5};
    t_point     begin = {7, 4};
    
    i = 0;
    area = make_area(zone, size);
    while (i < size.y)
    {
        printf("%s\n", area[i]);
        i++;
    }
    printf("\n");
    flood_fill(area, size, begin);
    i = 0;
    while (i < size.y)
    {
        printf("%s\n", area[i]);
        i++;
    }
    return(0);
}

