/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_test_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:42:35 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/23 15:28:31 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*head_a;
	t_stack	*list_b;
	t_stack	*head_b;
	int		flag;

	++argv;
	if (argc <= 1)
	{
		ft_printf("[TEST] No arguments\n\n");
		ft_printf("=================== END TEST ===================\n\n");
		return (0);
	}
	flag = -1;
	if (ft_strncmp(*argv, "--simple", 9) == 0)
		flag = 0;
	else if (ft_strncmp(*argv, "--medium", 9) == 0)
		flag = 1;
	else if (ft_strncmp(*argv, "--complex", 10) == 0)
		flag = 2;
	else if (ft_strncmp(*argv, "--adaptative", 13) == 0)
		flag = 3;
	if (flag != -1)
		++argv;
	else
		flag = 1;
	list_a = first_node((const t_stack *)build_list(argv));
	if (!list_a)
		return(error());
	list_b = NULL;
	if (flag == 0)
	{
		if (insertion_sort(&list_a, &list_b) == ERROR)
			return (ERROR);
	}
	else if (flag == 1)
	{
		if (chunk_sort(&list_a, &list_b) == ERROR)
			return (ERROR);
	}
	head_b = list_b;
	head_a = list_a;
	while (list_a)
	{
		ft_printf("[TEST A] node content: %i\n", list_a->value);
		list_a = list_a->next;
	}
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
