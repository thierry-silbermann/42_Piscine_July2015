
#include "ft_list.h"
#include <stdio.h>

void print_list(t_list *root) {
	while (root) 
	{
		printf("%c ", (char)(root->data));
		root = root->next;
	}
	printf("\n");
}

t_list *reverse(t_list* root) 
{
	t_list *new_root; 
		
	new_root = 0;
	while (root) 
	{
		t_list *next = root->next;
		root->next = new_root;
		new_root = root;
		root = next;
	}
	return (new_root);
}


int main(void) 
{
	char str_d[] = "d";
	char str_c[] = "c";
	char str_b[] = "b";
	char str_a[] = "a";

	t_list d = {  0 , &str_d };
	t_list c = { &d , &str_c };
	t_list b = { &c , &str_b };
	t_list a = { &b , &str_a };

	t_list  *root = &a;
	print_list(root);
	root = reverse(root);
	print_list(root);

	return (0);
}
