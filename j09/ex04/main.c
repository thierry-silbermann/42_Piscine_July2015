#include <stdio.h>

char *ft_rot42(char *str);

int main(void)
{
	char str[] = "Bonjour";
	ft_rot42(str);
	printf("%s\n", str);
	return (0);
}
