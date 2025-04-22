/*Nome dell'assegnazione: str_capitalizer
File attesi: str_capitalizer.c
Funzioni permesse: write

Scrivi un programma che accetti una o più stringhe e, per 
ciascun argomento, metta in maiuscolo la prima lettera di ogni 
parola (se è una lettera ovviamente), metta in minuscolo il resto, 
e stampi il risultato sull'output standard, seguito da una nuova riga.
Una “parola” è definita come una parte della stringa separata da spazi,
tabulazioni, oppure dall'inizio o dalla fine della stringa.
Se una parola è composta da una sola lettera, questa deve essere 
scritta in maiuscolo.
Se non vengono passati argomenti, il programma deve semplicemente 
stampare una nuova riga.

esempi:
$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $*/

#include <unistd.h>

void ft_str_capitalizer(char *str)
{
    int i;
    char c;

    i = 1;
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        c = str[0] - 32;
        write(1, &c, 1);
    }
    else
        write(1, &str[0], 1);
    while (str[i])
    {
        if (str[i] == ' ')
        {
            write(1, &str[i], 1);
            i++;
        }
        else if(str[i - 1] != ' ' && !(str[i] >= 'A' && str[i] <= 'Z'))
        {
            write(1, &str[i], 1);
            i++;
        }
        else if(str[i - 1] != ' ' && (str[i] >= 'A' && str[i] <= 'Z'))
        {
            c = str[i] + 32;
            write(1, &c, 1);
            i++;
        }
        else if(str[i - 1] == ' ' && (str[i] >= 'a' && str[i] <= 'z'))
        {
            c = str[i] - 32;
            write(1, &c, 1);
            i++;
        }
        else if(str[i - 1] == ' ' && (str[i] >= 'A' && str[i] <= 'Z'))
        {
            write(1, &str[i], 1);
            i++;
        }
        else
            i++;
    }
}

int main (int ac, char **av)
{
    int i;

    i = 1;
    if (ac < 1)
        write(1, "\n", 1);
    else
    {
        while(av[i])
        {
            ft_str_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }

}