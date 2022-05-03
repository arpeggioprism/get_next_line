#ifndef get_next_line_h
#define get_next_line_h

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

#endif
