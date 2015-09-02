#include <stdio.h>

char *ft_concat_params(int argc, char **argv);

int main(int argc, char **argv)
{
	printf("%s\n", ft_concat_params(argc, argv));
	return (0);
}
