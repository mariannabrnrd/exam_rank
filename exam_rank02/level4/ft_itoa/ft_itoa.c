#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_count_len(int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		count = 1;
		return(count);
	}
	if (num < 0)
	{
		count = 1;
		num = -num;
	}
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	return(count);
}

char	*ft_itoa(int nbr)
{
	long int 	num;
	char 		*dest;
	int 		len;

	num = nbr;
	len = ft_count_len(num);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return(NULL);
	dest[len] = '\0';
	if (num == 0)
	{
		dest[0] = '0';
		return(dest);
	}
	else if (num < 0)
	{
		dest[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		len--;
		dest[len] = (num % 10) + '0';
		num = num / 10;	
	}
	return(dest);
}

/* ---------------------main per testare--------------------------- */

int     main(void)
{
    char    *str;

    str = ft_itoa(-5643);
    printf("numero: %s\n", str);
    free(str);

    return(0);
}