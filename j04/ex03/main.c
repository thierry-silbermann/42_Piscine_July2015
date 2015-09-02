#include <stdio.h>

int ft_recursive_power(int nb, int power);

int main(void)
{
	printf("%d\n", ft_recursive_power(2, -10));
	printf("%d\n", ft_recursive_power(2, 0));
	printf("%d\n", ft_recursive_power(2, 1));
	printf("%d\n", ft_recursive_power(2, 10));
	printf("%d\n", ft_recursive_power(2, 12));
	printf("%d\n", ft_recursive_power(10, 3));
	return (0);
}
