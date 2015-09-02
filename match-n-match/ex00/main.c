
#include <stdio.h>

int	match(char *s1, char *s2);

void print(char *s1, char *s2, int bool)
{
	if (bool)
		printf("%s / %s / Match !\n", s1, s2);
	else
		printf("%s / %s / No Match !\n", s1, s2);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Erreur\n");
		return (0);
	}
	int bool;

	bool = match(argv[1], argv[2]);
	print(argv[1], argv[2], bool);
	printf("###### Test ######\n");

	char *a1 = "main.c";
	char *a2 = "*.c";
	print(a1, a2, match(a1, a2));

	char *a13 = "main.c";
	char *a14 = "ma*";
	print(a13, a14, match(a13, a14));

	char *a3 = "main.c";
	char *a4 = "m*d";
	print(a3, a4, match(a3, a4));

	char *a5 = "main.c";
	char *a6 = "m*.";
	print(a5, a6, match(a5, a6));

	char *a7 = "main.c";
	char *a8 = "*a*.c";
	print(a7, a8, match(a7, a8));

	char *a9 = "main.c";
	char *a10 = "m*a*i*n*.*c";
	print(a9, a10, match(a9, a10));

	char *a11 = "main.c";
	char *a12 = "mbin.c";
	print(a11, a12, match(a11, a12));

	char *a15 = "plopblablablo";
	char *a16 = "plop*blo";
	print(a15, a16, match(a15, a16));

	return (0);
}
