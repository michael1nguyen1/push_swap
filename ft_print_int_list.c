#include "push_swap.h"

void	ft_print_intlst(t_push_list *list)
{
	while (list)
	{
		ft_printf("%i", list->num);
		list = list->next;
	}
}
