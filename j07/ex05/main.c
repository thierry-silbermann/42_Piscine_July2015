#include <stdio.h>

int get_nb_words(char *str);
int get_location(int i, char *str, int tab[]);
char **ft_split_whitespaces(char *str);
void ft_print_words_tables(char **tab);

int	main(void)
{
	int tab[1];
	int i;
	char **c;
	char str[] = "  Je    veux \t tester   si           ca  \n  fonctionne";
	printf("%d\n", get_nb_words(str));
	i = get_location(5, str, tab);
	printf("Size: %d / Beg: %d\n", tab[0], i);
	c = ft_split_whitespaces(str);
	/*while (*c){
		printf("%s\n", *c);
		c++;
	}*/
	printf("##############\n");
	ft_print_words_tables(c);
	printf("##############\n");
	return (0);
}
