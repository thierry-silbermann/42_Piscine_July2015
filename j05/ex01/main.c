#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
	char dest[100];
	char src[40];
	ft_strncpy(src, "Je test cette merde", 19);
	ft_strncpy(dest, src, 10);
	printf("%s\n", dest);
	return (0);
}
