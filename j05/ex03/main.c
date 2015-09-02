#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s, char *s2);

int main ()
{
	char str1[15];
	char str2[15];
	int ret;

	strcpy(str1, "abcde");
	strcpy(str2, "ABCD");

	ret = strcmp(str1, str2);
	if(ret < 0)
		printf("str1 is less than str2\n");
	else if(ret > 0) 
		printf("str2 is less than str1\n");
	else 
		printf("str1 is equal to str2\n");
	

	char str3[15];
	char str4[15];

	strcpy(str3, "abcde");
	strcpy(str4, "ABCD");

	ret = strcmp(str3, str4);
	if(ret < 0)
		printf("str1 is less than str2\n");
	else if(ret > 0) 
		printf("str2 is less than str1\n");
	else 
		printf("str1 is equal to str2\n");
	
	
	return(0);
}
