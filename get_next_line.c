#include<stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


/* SE O NUMERO DE bytes lidos for 
 * menor que o buffer, pode ser
 * que chegou ao final do arquivo.
 *  ssize_t read(int fildes , void * buf , size_t nbyte ); */


char	*read_content(fd, content)
{
	int	i;
	
	read(fd, content, BUFFER_SIZE);
//verificar erros de leitura resultante da operação acima 
//
	return (content);
}

char	*strip_line(content)
{
	// recebe o conteudo do arquivo e devolve 
	// uma linha do mesmo
	
}

char	*get_rest(content)
{
//	recebe o conteudo do arquivo remove a linha que foi lida e 
//	guarda o restante para proxima leitura
}

char *getline(fd)
{
	char	*linha;
	char	*conteudo;
	int		i;

	linha = malloc(sizeof(char)*BUFFER_SIZE);
	conteudo = malloc(sizeof(char)*1);
		i = 0;
}


int main() 
{ 
	char	*nextline;
	int		fd = open("foo.txt", O_RDONLY); 

	if (fd < 0) 
    { 
        perror("c1"); 
        exit(1); 
    } 
//    printf("Valor do FD = %d\n\n", fd);
   	
	nextline = get_next_line(fd);
	
	printf("%s", nextline);
	
    if (close(fd) < 0) 
    { 
        perror("c1"); 
        exit(1); 
    } 
   printf("\nclose the fd.\n");
   return (0);
}


char *get_next_line(int fd)
{
	char		*line;
	char		*content;
	static char	*reserve;
	int			i;

	if ((read(fd, 0, 0) < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	content = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!content)
		return (NULL);
//conteudo abaixo é util na pós leitura do arquivo
//	if (BUFFER_SIZE >= 0)
//		content[BUFFER_SIZE] = '\0';
	if (!reserve)
		reserve = strdup("\0"); // ???
	content = read_content(fd, content);
	line = strip_line(content);
	reserve = get_rest(content);	
	}
	free(content);
	return (line);
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
