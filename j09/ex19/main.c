#include <stdio.h>

int ft_unmatch(int *tab, int length);

int main(void)
{
	int tab[7] = {1, 1, 3, 4, 3, 4, 2};
	printf("%d\n", ft_unmatch(tab, 7));
	
	int tab2[5] = {6, 6, 3, 10, 3};
	printf("%d\n", ft_unmatch(tab2, 5));
	
	int tab3[11] = {10, 1, 1, 3, 4, 677, 3, 4, 677, 9, 10};
	printf("%d\n", ft_unmatch(tab3, 11));
	
	int tab4[1] = {10};
	printf("%d\n", ft_unmatch(tab4, 1));
	return (0);
}
