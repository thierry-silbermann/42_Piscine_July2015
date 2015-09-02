#include <stdio.h>

int ft_find_next_prime(int nb);

int main(void)
{
	printf("%d\n", ft_find_next_prime(-10));
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(1));
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(3));
	printf("%d\n", ft_find_next_prime(4));
	printf("%d\n", ft_find_next_prime(5));
	printf("%d\n", ft_find_next_prime(9));
	printf("%d\n", ft_find_next_prime(10));
	printf("%d\n", ft_find_next_prime(31));
	printf("%d\n", ft_find_next_prime(101));
	printf("%d\n", ft_find_next_prime(1073742091));
	printf("%d\n", ft_find_next_prime(1073742092));
	return (0);
}
