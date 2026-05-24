/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_test_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:42:35 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/24 02:37:50 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Revise the first argv to see if its any of the valid flags.
 * @param stack Pointer to the strings of argv.
 * @return -1, 0, 1, 2 or 3 depending on the algorithm selected.
 */
static int	select_flag(char ***argv)
{
	int	flag;

	flag = -1;
	if (ft_strncmp(**argv, "--simple", 9) == 0)
		flag = 0;
	else if (ft_strncmp(**argv, "--medium", 9) == 0)
		flag = 1;
	else if (ft_strncmp(**argv, "--complex", 10) == 0)
		flag = 2;
	else if (ft_strncmp(**argv, "--adaptative", 13) == 0)
		flag = 3;
	if (flag != -1)
		++(*argv);
	else
		flag = 3;
	return (flag);
}

/**
 * @brief Control the disorder_index to choice the correspondent algorithm.
 * @param disorder_index The index of disorder of the stack.
 * @return 0, 1, 2 controlling which algorithm is going to be launch.
 */
static int	select_by_disorder(double disorder_index)
{
	if (disorder_index < 0.2)
		return (0);
	else if (disorder_index < 0.5)
		return (1);
	else
		return (2);
}

/**
 * @brief Depend on the flag given launch any of the three algorithms.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param flag The flag which is the algorithm selected.
 * @return 0 is all is okey, ERROR in other cases.
 */
static int	launch_algorithm(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (flag == 0)
	{
		if (insertion_sort(stack_a, stack_b) == ERROR)
			return (ERROR);
	}
	else if (flag == 1)
	{
		if (chunk_sort(stack_a, stack_b) == ERROR)
			return (ERROR);
	}
	else if (flag == 2)
		radix_sort(stack_a, stack_b, lst_size(*stack_a));
	return (0);
}

/**
 * @brief Controll a safe exit by freeing both stacks
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 */
static void	free_both(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int		flag;

	++argv;
	if (argc <= 1)
		return (0);
	flag = select_flag(&argv);
	list_a = first_node((const t_stack *)build_list(argv));
	if (!list_a)
		return (error());
	list_b = NULL;
	if (flag == 3)
		flag = select_by_disorder(compute_disorder(list_a));
	if (launch_algorithm(&list_a, &list_b, flag) == ERROR)
	{
		free_both(&list_a, &list_b);
		return (error());
	}
	free_both(&list_a, &list_b);
	return (0);
}
