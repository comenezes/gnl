/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenezes <cmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:05:02 by cmenezes          #+#    #+#             */
/*   Updated: 2022/11/12 21:20:55 by cmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *ch)
{
	size_t	i;

	i = 0;
	while (ch[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*chjoin;
	size_t	size1;
	size_t	size2;

	i = 0;
	j = 0;
	size1 = ft_strlen (s1);
	size2 = ft_strlen (s2);
	
	chjoin = malloc (size1 + size2 + 1);
	if (chjoin == NULL)
		return (NULL);
	while (s1 [i])
	{
		chjoin [i] = s1 [i];
		i++;
	}
	while (s2 [j])
	{
		chjoin [i + j] = s2 [j];
		j++;
	}
	chjoin [i + j] = '\0';
	free(s1);//Alterei aqui **Free na variavel estatica**
	return (chjoin);
}

int	ch_find_nl(char *text)
{
	int	i;

	i = 0;
	while (text [i])
	{
		if (text [i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
