#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char    *s;

void error(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
    exit(1);
}

int expr();
int term();

int     factor()
{
    int val;

    if (isdigit(*s))
        return(*s++ - '0');
    if (*s == '(')
    {
        s++;
        val = expr();
        if (*s != ')')
            error(*s);
        s++;
        return(val);
    }
    error(*s);
    return(0);
}

int term()
{
    int     val;

    val = factor();
    while (*s == '*')
    {
        s++;
        val *= factor();
    }
    return (val);
}

int expr()
{
    int     val;

    val = term();
    while (*s == '+')
    {
        s++;
        val += term();
    }
    return (val);
}

int     main(int ac, char **av)
{
    int     result;

    if (ac != 2)
        return (1);
    s = av[1];
    result = expr();
    if (*s)
        error(*s);
    printf("%d\n", result);
    return(0);
}
