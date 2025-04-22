/* Nome dell'esercizio: ft_split
File richiesti: ft_split.c
Funzioni permesse: malloc

Scrivi una funzione che prende in input una stringa, la divide in parole e
le restituisce sotto forma di array di stringhe, con un puntatore nullo (NULL) alla fine.

Una "parola" è definita come una parte della stringa delimitata da spazi, tabulazioni (\t),
a capo (\n), oppure dall'inizio o dalla fine della stringa.

La tua funzione deve essere dichiarata nel seguente modo:

char **ft_split(char *str);*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while(i < n && s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return(s1);
}

int count_word(char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        if (!(*str == ' ' || *str == '\t' || *str == '\n'))
        {
            count++;
            while (*str && !(*str == ' ' || *str == '\t' || *str == '\n'))
            {
                str++;
            }
        }
        else
            str++;
        
    }
    return (count);
    
}

char **ft_split(char *str)
{
    char **phrase;
    int i;
    int j;
    int k;

    k = 0;
    i = 0;
    j = 0;
    phrase = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
    if (!phrase)
        return(0);
    while(str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        j = i;
        while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (i > j)
        {
            phrase[k] = (char *)malloc(sizeof(char) * (i - j) + 1);
            ft_strncpy(phrase[k], &str[j], i - j);
            k++;
        }

    }
    phrase[k] = NULL;
    return(phrase);
}

/* MAIN ****************************************************************************************** */
int main(int ac, char **av)
{
    int i;
    char **split;

    i = 0;
    split = ft_split(av[1]);
    printf("stringa originale : %s\n", av[1]);
    while(split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]);
        i++;
    }
    free(split);
    return(0);
}