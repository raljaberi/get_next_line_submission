/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:52:41 by raljaber          #+#    #+#             */
/*   Updated: 2024/03/06 10:57:57 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *strread)
{
	char	*buff;
	int		numofbytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	numofbytes = 1;
	while (numofbytes != 0)
	{
		numofbytes = read(fd, buff, BUFFER_SIZE);
		if (numofbytes == -1)
		{
			free(buff);
			free(strread);
			return (NULL);
		}
		buff[numofbytes] = '\0';
		strread = ft_strjoin(strread, buff);
		if (ft_strchr(strread, '\n'))
			break ;
	}
	free(buff);
	return (strread);
}

char	*ft_get_line(char *strread)
{
	int		i;
	char	*line;

	i = 0;
	if (!strread[i])
		return (NULL);
	while (strread[i] && strread[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (strread[i] && strread[i] != '\n')
	{
		line[i] = strread[i];
		i++;
	}
	if (strread[i] == '\n')
	{
		line[i] = strread[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_remaining(char *strread)
{
	int		i;
	int		c;
	char	*remaining;

	i = 0;
	while (strread[i] && strread[i] != '\n')
		i++;
	if (!strread[i])
	{
		free(strread);
		return (NULL);
	}
	remaining = (char *)malloc(sizeof(char) * (ft_strlen(strread) - i + 1));
	if (!remaining)
		return (NULL);
	i++;
	c = 0;
	while (strread[i])
		remaining[c++] = strread[i++];
	remaining[c] = '\0';
	free(strread);
	if (remaining[0] == 0)
		return (free(remaining), NULL);
	return (remaining);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strread;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	strread = ft_read(fd, strread);
	if (!strread)
		return (NULL);
	line = ft_get_line(strread);
	strread = ft_remaining(strread);
	return (line);
}
