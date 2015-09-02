#include <stdio.h>

void 	ft_strcpy(char *a, char *b);

void	ft_putnbr_base(int nb, char *base);

int main(void)
{
	char c[7];

	ft_strcpy(c, "qwerty");
	ft_putnbr_base(0, c); // Q
	printf("\n");
	ft_putnbr_base(1, c); // W
	printf("\n");
	ft_putnbr_base(2, c); // E 
	printf("\n");
	ft_putnbr_base(3, c); // R
	printf("\n");
	ft_putnbr_base(4, c); // T
	printf("\n");
	ft_putnbr_base(5, c); // Y
	printf("\n");
	ft_putnbr_base(6, c); // WQ
	printf("\n");
	ft_putnbr_base(11, c); // WY
	printf("\n");
	ft_putnbr_base(12, c); // EQ
	printf("\n");
	ft_putnbr_base(3125, c); // EEETY
	printf("\n");
	return (0);
}
