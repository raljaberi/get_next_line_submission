/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:52:46 by raljaber          #+#    #+#             */
/*   Updated: 2024/03/06 10:59:08 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *) str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	total_len;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, total_len + 1);
	if (s1)
		free(s1);
	return (result);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dest == NULL && src == NULL)
		return (0);
	while (i < size && dest[i])
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
