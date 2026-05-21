#include "push_swap.h"

int main(int argc, char **argv)
{
	int	i;
	t_stack *list_a;
	t_stack *head_a;
	t_stack *list_b;
	t_stack *head_b;

	i = 0;
	++argv;
	
	ft_printf("=================== INITIAL TEST ===================\n\n");
	if (argc <= 1)
	{
		ft_printf("[TEST] No arguments\n\n");
		ft_printf("=================== END TEST ===================\n\n");
		return (0);
	}
	/*
	//ft_printf("[TEST] Testing program with argv: \n");
	while (argv[i])
		ft_printf("[TEST]-> %s\n", argv[i++]);
	*/
	list_a = first_node((const t_stack *)build_list(argv));
	if (!list_a)
		return (-1);
	list_b = NULL;
	insertion_sort(&list_a, &list_b);
	head_a = list_a;
	/*
	while (list_a)
	{
		ft_printf("[TEST A] node content: %i\n", list_a->value);
		list_a = list_a->next;
	}
	*/
	head_b = list_b;
	/*
	while (list_b)
	{
		ft_printf("[TEST B] node content: %i\n", list_b->value);
		list_b = list_b->next;
	}
	*/
	free_stack(&head_a);
	free_stack(&head_b);

	ft_printf("=================== END TEST ===================\n\n");
	return (0);
}