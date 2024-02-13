
#include "push_swap.h"

void ft_print_intlist(t_push_list *a, t_push_list *b)
{
	t_push_list *temp;
	temp = a;
	while(a)
	{
		printf("A list\n num:%d index:%d median:%d cost:%d \n", a->num , a->index, a->median, a->cost);
		a = a->next;
	}
	a = temp;

	if(!b)
		return;
	temp = b;
	while(b)
	{
		printf("B list\n num:%d index:%d median:%d target_num: %d cost:%d\n", b->num , b->index, b->median, b->target->num, b->cost);
		b = b->next;
	}
	b = temp;


	// if(!b)
	// 	return;
	// temp = b;
	// while(b)
	// {
	// 	printf("B list\n num:%d index:%d median:%d cost:%d\n", b->num , b->index, b->median, b->cost);
	// 	b = b->next;
	// }
	// b = temp;
}