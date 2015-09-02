
#include <stdio.h>

int	nmatch(char *s1, char *s2);

void print(char *s1, char *s2, int bool)
{
	printf("%s / %s / %d !\n", s1, s2, bool);
}

int main(int argc, char **argv)
{
	if (argc != 3 && argc != 1)
	{
		printf("Erreur\n");
		return (0);
	}
	if (argc == 3)
	{
		int bool;

		bool = nmatch(argv[1], argv[2]);
		print(argv[1], argv[2], bool);
		printf("###### Test ######\n");
	}

	printf("###### Test ######\n");
	char *a5 = "abcbd";
	char *a6 = "*b*";
	print(a5, a6, nmatch(a5, a6));

	printf("###### Test ######\n");
	char *a9 = "abc";
	char *a10 = "a**";
	print(a9, a10, nmatch(a9, a10));

	printf("###### Test ######\n");
	char *a1 = "main.c";
	char *a2 = "*.c";
	print(a1, a2, nmatch(a1, a2));

	char *a3 = "main.c";
	printf("###### Test ######\n");
	char *a4 = "m*d";
	print(a3, a4, nmatch(a3, a4));

	printf("###### Test ######\n");
	char *a7 = "main.c";
	char *a8 = "*a*.c";
	print(a7, a8, nmatch(a7, a8));

	printf("###### Test ######\n");
	char *a15 = "plopblablablo";
	char *a16 = "plop*b*lo";
	print(a15, a16, nmatch(a15, a16));

	return (0);
}
