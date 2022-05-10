/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:59:06 by jshin             #+#    #+#             */
/*   Updated: 2022/05/10 17:21:15 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_join(int fd, char *save);
int		nl_in_buf(char *buf);
char	*resultline(char *save);
char	*linesave(char *save);

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!save[fd])
		save[fd] = (char *)ft_calloc(1, sizeof(char));
	if (!save[fd])
		return (NULL);
	save[fd] = read_join(fd, save[fd]);
	res = resultline(save[fd]);
	save[fd] = linesave(save[fd]);
	return (res);
}

char	*read_join(int fd, char *save)
{
	char	*temp;
	char	*buf;
	int		rbyte;

	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	while (!nl_in_buf(buf))
	{
		rbyte = read(fd, buf, BUFFER_SIZE);
		if (rbyte == -1)
		{
			free(save);
			free(buf);
			return (NULL);
		}
		buf[rbyte] = '\0';
		if (rbyte == 0)
			break ;
		temp = save;
		save = ft_strjoin(save, buf);
		free(temp);
	}
	free(buf);
	return (save);
}

int	nl_in_buf(char *buf)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*resultline(char *save)
{
	char	*res;
	int		i;
	int		j;

	if (!save[0])
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	if (!res)
		return (NULL);
	j = i;
	i = 0;
	while (i < j)
	{
		res[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*linesave(char *save)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	j = i + 1;
	new = (char *)ft_calloc(ft_strlen(save) - i + 2, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (save[j])
		new[i++] = save[j++];
	free(save);
	return (new);
}
