#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void 	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void 	ft_putstr(char *str, int *count)
{
	int 	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", count);
		return;
	}
	while(str[i])
		ft_putchar(str[i++], count);
}

void 	ft_putnbr(int nbr, int *count)
{
	long int 	num;
	char 		c;

	num = nbr;
	if (num < 0)
	{
		ft_putchar('-', count);
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10, count);
	c = (num % 10) + '0';
	ft_putchar(c, count);
}

void 	ft_puthex(unsigned int num, int *count)
{
	char 	c;

	if (num >= 16)
	{
		ft_puthex(num / 16, count);
		ft_puthex(num % 16, count);
	}
	else
	{
		if (num <= 9)
		{
			c = num + '0';
			ft_putchar(c, count);
		}
		else
		{
			c = num - 10 + 'a';
			ft_putchar(c, count);
		}
	}
}

int 	ft_printf(char *str, ...)
{
	va_list 	args;
	int 		count;
	int 		i;

	i = 0;
	count = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (str[i] == 'd')
				ft_putnbr(va_arg(args, int), &count);
			else if (str[i] == 'x')
				ft_puthex(va_arg(args, unsigned int), &count);
			else
				ft_putchar(str[i], &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(args);
	return(count);
}
