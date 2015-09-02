unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
	char a = "pouet pouet";
	char b = "baka";
	ft_strlcat(b, a, 5);
	return (0);
}
