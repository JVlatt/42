#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, const void *buf, size_t count);
size_t 	ft_strlen(const char *s);
int 	ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	char* str = malloc(1000);
	ft_read(0, str, 1000);
	ft_write(1, str, 1000);
	printf("ft_strlen : %ld\n", ft_strlen(str));
	printf("strlen : %ld\n", strlen(str));
	printf("strcmp : %d\n", strcmp("toto", "tata"));
	printf("ft_strcmp : %d\n", ft_strcmp("toto", "tata"));
	return 0;
}
