/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:20:49 by lupin             #+#    #+#             */
/*   Updated: 2026/05/18 20:48:09 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	i;
	t_stack *list;
	t_stack *head;

	i = 0;
	++argv;
	ft_printf("=================== INITIAL TEST ===================\n\n");
	if (argc <= 1)
	{
		ft_printf("[TEST] No arguments\n\n");
		ft_printf("=================== END TEST ===================\n\n");
		return (0);
	}
	ft_printf("[TEST] Testing program with argv: \n");
	while (argv[i])
		ft_printf("[TEST]-> %s\n", argv[i++]);
	list = first_node((const t_stack *)build_list(argv));
	head = list;
	while (list)
	{
		ft_printf("[TEST] node content: %i\n", list->value);
		list = list->next;
	}
	free_stack(&head);
	ft_printf("=================== END TEST ===================\n\n");
	return (0);
}
