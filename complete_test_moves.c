#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *list_a;
	t_stack *head_a;
	t_stack *list_b;
	t_stack *head_b;

	++argv;	
	if (argc <= 1)
	{
		ft_printf("[TEST] No arguments\n\n");
		ft_printf("=================== END TEST ===================\n\n");
		return (0);
	}
	list_a = first_node((const t_stack *)build_list(argv));
	if (!list_a)
		return (-1);
	list_b = NULL;
	if (insertion_sort(&list_a, &list_b) == ERROR)
		return (ERROR);
	head_a = list_a;
	while (list_a)
	{
		ft_printf("[TEST A] node content: %i\n", list_a->value);
		list_a = list_a->next;
	}
	head_b = list_b;
	ft_printf("-----------------------------");
	while (list_b)
	{
		ft_printf("[TEST B] node content: %i\n", list_b->value);
		list_b = list_b->next;
	}
	free_stack(&head_a);
	free_stack(&head_b);
	return (0);
}