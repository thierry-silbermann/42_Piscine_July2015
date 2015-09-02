#include <stdio.h>

int ft_is_prime(int nb);

int main(void)
{
	printf("%d\n", ft_is_prime(-10));
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(3));
	printf("%d\n", ft_is_prime(4));
	printf("%d\n", ft_is_prime(5));
	printf("%d\n", ft_is_prime(9));
	printf("%d\n", ft_is_prime(10));
	printf("%d\n", ft_is_prime(31));
	printf("%d\n", ft_is_prime(101));
	printf("%d\n", ft_is_prime(1073742113));
	
	printf("#######\n");
	
	printf("%d\n", ft_is_prime(10607));
	printf("%d\n", ft_is_prime(10603));
	printf("%d\n", ft_is_prime(10609));
	printf("%d\n", ft_is_prime(43783));
	printf("%d\n", ft_is_prime(49999));
	printf("%d\n", ft_is_prime(47021));
	return (0);
}
