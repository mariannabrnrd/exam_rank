#include "get_next_line.h"

char    *ft_strdup(char *str)
{
    char    *new;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while(str[i])
        i++;
    new = (char *)malloc(i + 1);
    if (!new)
        return(NULL);
    while (str[j])
    {
        new[j] = str[j];
        j++;
    }
    new[j] = '\0';
    return(new);
}

char    *get_next_line(int fd)
{
    static char     buff[BUFFER_SIZE];
    static int      bytes_read;
    static int      buff_pos;
    char            line[70000];
    int             i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    while (1)
    {
        if (buff_pos >= bytes_read)
        {
            bytes_read = read(fd, buff, BUFFER_SIZE);
            buff_pos = 0;
            if (bytes_read <= 0)
                break;
        }
        line[i++] = buff[buff_pos++];
        if (line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return(NULL);
    return(ft_strdup(line));
}

/*---------------------main per testare----------------------------------------------------*/

int     main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return(0);
}
