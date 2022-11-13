/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenezes <cmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 06:53:02 by cmenezes          #+#    #+#             */
/*   Updated: 2022/11/12 20:56:02 by cmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    char	*nextline;
    int		fd = open("loreip.txt", O_RDONLY);

    if (fd < 0)
    {
        perror("c1");
        exit(1);
    }

	int i = 35;
	while (i)
	{
		nextline = get_next_line(fd);
    	printf("%s", nextline);
		i--;
	}

    if (close(fd) < 0)
    {
        perror("c1"); //atencao
        exit(1);
    }
    printf("**close the fd.**");
    return (0);
}

