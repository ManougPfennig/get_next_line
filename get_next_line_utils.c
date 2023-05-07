/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:39:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/05 16:56:48 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		length;
	char	*dest;

	i = 0;
	j = 0;
	length = 0;
	while (s1 && s1[i++])
		length++;
	while (s2 && s2[j++])
		length++;
	i = 0;
	j = 0;
	dest = ft_calloc((length + 1), sizeof(char));
	while (s1 && s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		dest[j++] = s2[i++];
	ft_freestr(&s1);
	ft_freestr(&s2);
	return (dest);
}

void	ft_freestr(char **ptr)
{
	if ((*ptr) != NULL)
	{
		free((*ptr));
		(*ptr) = NULL;
	}
	return ;
}

char	*ft_clean_up(char **ptr, char **ptr2)
{
	ft_freestr(ptr);
	ft_freestr(ptr2);
	return (NULL);
}
