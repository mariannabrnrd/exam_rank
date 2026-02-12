#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    enum { ADD, MULTI, VAL }type;
    int         val;
    struct node *l;
    struct node *r;
} node;

int main (int ac, char **av)
{
    char    *str;
    node    *tree;

    if (ac != 2)
        return 1;
    str = av[1];
    tree = parse_add(&str);
    if (!tree)
        return (-1);
    
}