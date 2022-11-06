#include<stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


char *getline()
{
	
}

char *get_next_line(int fd)
{
	char		*linha;
	char		*conteudo;
	int			i = 0;

	linha = malloc(sizeof(char)*BUFFER_SIZE);
	conteudo = malloc(sizeof(char)*1);
	if ((read(fd, linha, 0) < 0) || (BUFFER_SIZE <= 0))
	{
		write(1,"Erro",4);
		return (NULL);
	}
	i = read(fd, linha, BUFFER_SIZE);
	if (BUFFER_SIZE >= 0)
		linha[BUFFER_SIZE] = '\0';
	if (BUFFER_SIZE <= 0)
		linha[0] = '\0';
	i = 0;
	while (linha[i] != '\n' && linha[i] != '\0')
	{
		printf("%c", linha[i]);
		i++;
		// se  linha[i] != '\0'
		// 		conteudo <<- linha (usar uma função para concatenar)		
		//		i <- 0
		//
	}
	return (conteudo);
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

