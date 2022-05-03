/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:03:11 by jshin             #+#    #+#             */
/*   Updated: 2022/05/03 20:20:18 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	static char *next_adr;
	char *buf;
	char *line;
	int ridden_char;

	buf = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if(!buf)
		return (NULL);

	ridden_char = read(fd, buf, BUFFER_SIZE);
	if (ridden_char == -1)
	{
		free(buf);
		return (NULL);
	}
	
	if(next_adr)
		buf = next_adr;
	int i;
	
	i = 0;
	while(buf[i])
	{
		if(buf[i] == '\n')
		{

			next_adr = buf + i + 1;
			buf[i] = '\0';
			return (line);
		}
		i++;
	}
	buf += ridden_char;
	return buf;
}

#include <stdio.h>

int main(void)
{
	int fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", str = get_next_line(fd));
	printf("%s\n", str = get_next_line(fd));
}