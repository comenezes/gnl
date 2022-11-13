/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenezes <cmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:53:12 by cmenezes          #+#    #+#             */
/*   Updated: 2022/11/12 21:23:36 by cmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
char	*read_content(int fd, char *content)
{
	int		nbytes;
	char	*temp;

	temp = malloc (sizeof(char) * (BUFFER_SIZE + 1));//Alterei aqui ** Antes o BUFFER_SIZE era 2**
	if (!temp)
		return (NULL);
	nbytes = 1;
	while (nbytes != 0 && !ch_find_nl (temp))
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[nbytes] = '\0';
		content = ft_strjoin (content, temp); //alterei aqui **Cocatenacao na variavel statica**
	}
	free(temp);
	return (content);
}

char	*strip_line(char *content)
{
	int		i;
	char	*temp;

	i = 0;
	if(content[i] == '\0')//alterei aqui  ** Tratamento para verificar se a variavel estatica e nulo ** 
	{
		return NULL;
	}
	while (content [i] != '\n' && content [i] != '\0')
		i++;
	temp = malloc (sizeof (char) * i + 2);
	if (!temp)
	{
		return (NULL);
	}
	temp [i + 1] = '\0';
	while (i >= 0)
	{
		temp [i] = content [i];
		i--;
	}
	return (temp);
}

char	*get_rest(char *content)
{
	size_t	i;
	int		j;
	size_t	size;
	char	*temp;

	i = 0;
	if(content[i] == '\0')//alterei aqui ** Tratamento para verificar se a variavel estatica e nulo  e da um free nela ** 
	{
		free(content);
		return NULL;
	}
	while ((content[i] != '\n') && (content[i] != '\0'))
		i++;
	if (content [i] == '\n')
		i++;
	size = ft_strlen (content);
	temp = malloc (sizeof (char) * (size - i)+1);//alterei aqui ** coloquei o size - i entre parenteses 
	if (!temp)
		return (NULL);
	j = 0;
	while (content[i])
	{
		temp [j++] = content [i++];
	}
	temp [j] = '\0';//alterei aqui **Antes estava com j + 1 e tirei o +1**
	free (content);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*content;

	if ((read(fd, 0, 0) < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (!content)
	{
		if(content == NULL) //alterei aqui **A variavel estatica e inicializada como null e importante  fazer um malloc de 1 byte e colocar caracter para fazer a cocatenacao
	{
		content = malloc(1);
		content[0] = '\0';
	}
		if (!content)
			return (NULL);
		
	}
	content = read_content(fd, content);
	line = strip_line(content);
	content = get_rest(content);
	return (line);
}
