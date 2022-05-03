#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	int		fd;
	int		count;
	char	buf[100];

	char c;
	c = '\0';
	printf("%d", c);
	fd = open("./test.txt", O_RDWR | O_APPEND);
	printf("fd: %d\n", fd);
	if (fd < 0)
		printf("file open error");
	else
	{
		count = read(fd, buf, sizeof(buf));
		printf("%s\n", buf);
		printf("%d\n", count);
		close(fd);		
	}
	return (0);
}