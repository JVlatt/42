#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, const void *buf, size_t count);
size_t 	ft_strlen(const char *s);
int 	ft_strcmp(const char *s1, const char *s2);
char 	*ft_strcpy(char *dest, const char *src);
char 	*ft_strdup(const char *s);

int main(void)
{
	char* str = malloc(1000);
	ssize_t n = ft_read(0, str, 999);
	if (n > 0)
    	str[n] = '\0';
	ft_write(1, str, 1000);
	printf("ft_strlen : %ld\n", ft_strlen(str));
	printf("strlen : %ld\n", strlen(str));
	printf("strcmp : %d\n", strcmp("ab", "ae"));
	printf("ft_strcmp : %d\n", ft_strcmp("ab", "ae"));

	char dest[100];
	char *origin = "Tutu";

	printf("Before : [%s, %s]\n", origin, dest);
	ft_strcpy(dest, origin);
	printf("After : [%s, %s]\n", origin, dest);
	ft_strdup(origin);
	// printf("Dup : %s\n", dup);

	return 0;
}
