#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find);

int main()
{
	const char haystack[20] = "TutorialsPoint";
	const char needle[30] = "PointPointPointPoint";
	char haystack2[20] = "TutorialsPoint";
	char needle2[30] = "PointPointPointPoint";
	char *ret;
	char *ret2;

	ret = strstr(haystack, needle);
	printf("The substring is: %s\n", ret);
				      
	ret2 = ft_strstr(haystack2, needle2);
	printf("The substring is: %s\n", ret2);
	
	// #########
	
	const char haystack3[20] = "TutorialsPointTR";
	const char needle3[30] = "Point";
	char haystack4[20] = "TutorialsPointTR";
	char needle4[30] = "Point";
	char *ret3;
	char *ret4;

	ret3 = strstr(haystack3, needle3);
	printf("The substring is: %s\n", ret3);
				      
	ret4 = ft_strstr(haystack4, needle4);
	printf("The substring is: %s\n", ret4);

	return(0);
}
