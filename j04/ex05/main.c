#include <stdio.h>

int ft_sqrt(int nb);

int main(void)
{
	printf("%d\n", ft_sqrt(-10));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(10000));
	printf("%d\n", ft_sqrt(10001));
	printf("%d\n", ft_sqrt(2147302921));
	return (0);
}
