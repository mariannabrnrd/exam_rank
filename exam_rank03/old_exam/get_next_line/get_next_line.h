#ifndef     GET_NEXT_LINE
# define    GET_NEXT_LINE

#ifndef     BUFFER_SIZE
# define    BUFFER_SIZE
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd);
char    *ft_strdup(char *str);

#endif