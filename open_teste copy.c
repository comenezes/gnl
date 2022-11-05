#include<stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() 
{ 
	char	*myfile;
	int		buffer;
	char	*nextline;
	int		i;
	
	buffer = 500; 
	int fd1 = open("foo.txt", O_RDONLY); 
    if (fd1 < 0) 
    { 
        perror("c1"); 
        exit(1); 
    } 
    printf("opened the fd = %d\n\n", fd1); 
	buffer = read(fd1,myfile,buffer);
//		{
			myfile[buffer] = '\0';
//	   		printf("Content %s \n\n", myfile);
//		}
//	else 
//		printf("Error!");
	i = 0;
    while (i <= buffer)
		{
			if (myfile[i] == '\n')
			{ 
				write(1," <NL>!", 6);
			}
			write(1, myfile + i, 1);
			i++;
		}
	// Using close system Call 
    if (close(fd1) < 0) 
    { 
        perror("c1"); 
        exit(1); 
    } 
    printf("close the fd.\n"); 
}
