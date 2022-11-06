#include <stdio.h>


int soma(int n)
{
	if (n > 0) 
		 return (soma(n-1));
}
int main()
{
	printf("%d",soma(3));
	return (0);
}
