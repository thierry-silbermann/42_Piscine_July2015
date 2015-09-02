#include <stdio.h>

int ft_iterative_factorial(int nb);

int main(void)
{
	printf("%d\n", ft_iterative_factorial(-10));
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(1));
	printf("%d\n", ft_iterative_factorial(10));
	printf("%d\n", ft_iterative_factorial(12));
	printf("%d\n", ft_iterative_factorial(100));
	return (0);
}
