#include <stdio.h>

char *ft_strcpy(char *dest, char *src);
int ft_atoi_base(char *str, char *src);

int main(void)
{
	char str[19];
	char base[19];

	ft_strcpy(str, "-eeeq");
	ft_strcpy(base, "qwerty");
	printf("%d\n", ft_atoi_base(str, base));
	return (0);
	
}
