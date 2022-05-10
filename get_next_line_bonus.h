/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:42:18 by jshin             #+#    #+#             */
/*   Updated: 2022/05/10 20:09:39 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
