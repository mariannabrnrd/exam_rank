#include <stdio.h>
#include <stdlib.h>
#include <ctype.c>

typedef struct json {
    enum { MAP, INTEGER, STRING } type;
    union {
        struct {
            struct pair     *data;
            size_t          size;
        } map;
        int     integer;
        char    *string;
    }
} json;

typedef struct pair {
    char    *key;
    json    value;
} pair;

// guarda il prossimo carattere
int     next_char(FILE *f)
{
    int     c;

    c = getc(f);
    ungetc(c, f);
    return (c);
}

//caso di errore
void    error(FILE *f)
{
    int     c;

    c = next_char(f);
    if (c != EOF)
        printf("unexpected token '%c'\n", c);
    else
        printf("unexpected end of input\n");
}

// parsing del numero
int     parse_num(json *j, FILE *f)
{
    int     n;

    n = 0;
    fscanf(f, "%d", &n);
    j->type = INTEGER;
    j->integer = n;
    return (1);
}

// ritorna la stringa
int     get_str(FILE *f)
{
    int     i;
    char    c;
    char    str;

    i = 0;
    c = getc(f);
    str = calloc(4096, sizeof(char));

    while (1)
    {
        c = getc(f);
        if (c == '"')
            break;
        if (c == EOF)
        {
            error(f);
            return NULL;
        }
        if (c == '\\')
            c = getc(f);
        str[i++] = c;
    }
    return (str);
}

//verifica che i caratteri siano uguali
int     accept(FILE *stream, char c)
{
    if (next_char(f) == c)
    {
        (void)getc(f);
        return(1);
    }
    return (0);
}

//cerca il carattere dopo
int     expect(FILE *f, char c)
{
    if (accept(f, c))
        return (1);
    error(f);
    return (0);
}

//parsing della mappa
int     parse_map(json *j, FILE *f)
{
    pair    *curr;
    char    c;

    j->type = MAP;
    j->mapp.size = 0;
    j->map.data = NULL;

    getc(f);
    c = next_char(f);
    if (c == '}')
        return (1);
    while (1)
    {
        c = next_char(f);
        if (c != '"')
        {
            error(f);
            retrn (-1);
        }
        j->map.data = realloc(j->map.data, (j->map.size + 1) * sizeof (pair));
        curr = &j->map.data[j->map.size];
        curr->key = get_str(f);
        if (!curr->key)
            return (-1);
        j->map.size++;
        if (!expect(f, ":") == 0)
            return (-1);
        c = next_char(f);
        if (c == '}')
        {
            accept(f, c);
            break;
        }
        if (c == ',')
            accept(f, c);
        else
        {
            error(f);
            return (-1)
        }
        return (1);
    }

}

//inizio del parsing
int     argo(json *file, FILE *f)
{
    int     c;

    c = next_char(f);
    if (c == EOF)
    {
        error(f);
        return (-1);
    }
    if (isdigit(c))
        return(parse_num(j, f));
    else if (c == '"')
    {
        j->type = STRING;
        j->string = get_str(f);
        if (j->string == NULL)
            return(-1);
        return(1);
    }
    else if (c == '{')
        return(parse_map(j, f));
    /*else
    {
        error(f);
        return (-1);
    }
    return(1);*/
    error(f);
    return(-1);
}

int     main (int ac, char **av)
{
    FILE    *f;
    json    file;

    if (ac != 2)
        return (-1);

    f = fopen(av[1], "r");
    if (!f)
        return (1);
    if (argo(&file, f) != 1)
    {
        free_json(&file);
        fclose(f);
        return (1);
    }
    serialize(file);
    printf("\n");
    free_json(&file);
    fclose(f);
    return (0);
}