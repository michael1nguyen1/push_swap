
#include "push_swap.h"

void ft_print_intlist(t_push_list *longlist, t_push_list *shortlist)
{
	t_push_list *temp;
	temp = longlist;
	while(longlist)
	{
		printf("Long list\n num:%d index:%d median:%d target_num: %d cost:%d \n", longlist->num , longlist->index, longlist->median, longlist->target->num, longlist->cost);
		longlist = longlist->next;
	}
	longlist = temp;

	if(!shortlist)
		return;
	temp = shortlist;
	while(shortlist)
	{
		printf("Short list\n num:%d index:%d median:%d target_num: %d cost:%d\n", shortlist->num , shortlist->index, shortlist->median, shortlist->target->num, shortlist->cost);
		shortlist = shortlist->next;
	}
	shortlist = temp;
	// while(list)
	// {
	// 	printf("index: %d\n", list->index);
	// 	list = list->next;
	// }
	// list = temp;
	
	// while(list)
	// {
	// 	printf("median: %d\n", list->median);
	// 	list = list->next;
	// }
	// list = temp;
	// while(list)
	// {
	// 	printf("cost: %d\n", list->cost);
	// 	list = list->next;
	// }
	// list = temp;

	// while(list)
	// {
	// 	printf("target: %d\n", list->target->num);
	// 	list = list->next;
	// }
	// list = temp;

}