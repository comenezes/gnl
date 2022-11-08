#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 15 

size_t	ft_strlen(const char *ch)
{
    size_t     i;

    i = 0;
    while (ch[i] != '\0')
        i++;
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    int		i;
    int		j;
    char	*chjoin;

    i = 0;
    j = 0;
    chjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (chjoin == NULL)
        return (NULL);
    while (s1[i])
    {
        chjoin[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        chjoin[i + j] = s2[j];
        j++;
    }
    chjoin[i + j] = '\0';
    return (chjoin);
}

int ch_find_nl(char *text)
{
    int i;
    i = 0;
    while (text[i])
    {
        if (text[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char	*read_content(int fd, char *content)
{
    int	nbytes;
    char *temp;
    char *cache;

    temp = malloc(sizeof(char)*1);
    if (!temp)
        return(NULL);
    nbytes = 1;
    while (nbytes != 0 && !ch_find_nl(temp))
    {
        nbytes = read(fd, temp, BUFFER_SIZE);
        if (nbytes == -1)
        {
            free(temp);
            free(content);
            return (NULL);
        }
        temp[nbytes] = '\0';

        cache = ft_strjoin(content, temp);
        free (content);
        content = cache;
    }
    free(temp);
    return (content);
}

char	*strip_line(char *content)
{
    int     i;
    char    *temp;

    i = 0;
    while (content[i] != '\n' && content[i] != '\0')
        i++;
    temp = malloc(sizeof(char) * i + 2);
    temp[i+2] = '\0';
    temp[i+1] = '\n';
    while (i >= 0)
        {
            temp[i] = content[i];
            i--;
        }
//    printf("\n\n%s\n\n",temp);
    return(temp);
}

char	*get_rest(char *content)
{
    int     i;
	int		j;
    char    *temp;

  printf("STRLEN content: %ul\n\n", ft_strlen(content)); 
//	printf(content);
	i = 0;
    while ((content[i] != '\n') && (content[i] != '\0'))
        i++;
    temp = malloc(sizeof(char) * (ft_strlen(content) - i + 1));
	if (!temp)
		return(NULL);
	j = -1;
	while (i <= ft_strlen(content))
	{
		temp[++j] = content[i++];
		printf("%d",i);
		printf(" - %d\n",j); 
	}
//    temp[j+2] = '\0';
    temp[j+1] = '\n';
//	free(content);
//	content = temp;  
//    printf("\n\n%s\n\n",temp);
    return(temp);
}

char *get_next_line(int fd)
{
    char		    *line;
    static char		*content;
//  char	*reserve;
//  int			i;

    if ((read(fd, 0, 0) < 0) || (BUFFER_SIZE <= 0))
        return (NULL);
    if (!content)
    {
        content = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!content)
            return (NULL);
    }
    content = read_content(fd, content);
    line = strip_line(content);
	printf("*** %s", content);
//    content = get_rest(content);
//    free(content);

	//    printf("%s",line);
    return (line);
}

int main()
{
    char	*nextline;
    int		fd = open("texto.txt", O_RDONLY);

    if (fd < 0)
    {
        perror("c1");
        exit(1);
    }
	nextline = get_next_line(fd);
    printf("%s", nextline);
/*	nextline = get_next_line(fd);
    printf("%s", nextline);
	nextline = get_next_line(fd);
    printf("%s", nextline);
*/

    if (close(fd) < 0)
    {
        perror("c1"); //atencao
        exit(1);
    }
    printf("\n\nclose the fd.\n");
    return (0);
}

/*char    *get_next_line(int fd)
{
    char			*line;
    static char    *save;
    char        *buffer;
    if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    if (!save)
        save = ft_strdup("\0");
    save = get_buffer(fd, save, buffer);
    line = ft_read_line(save);
    save = ft_strip_sausage(save);
    free(buffer);
    return (line);
}*/
