/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_test_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:42:35 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/25 19:49:06 by lupin            ###   ########.fr       */
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
		flag = SIMPLE;
	else if (ft_strncmp(**argv, "--medium", 9) == 0)
		flag = MEDIUM;
	else if (ft_strncmp(**argv, "--complex", 10) == 0)
		flag = COMPLEX;
	else if (ft_strncmp(**argv, "--adaptative", 13) == 0)
		flag = ADAPTATIVE;
	if (flag != -1)
		++(*argv);
	else
		flag = ADAPTATIVE;
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
		return (SIMPLE);
	else if (disorder_index < 0.5)
		return (MEDIUM);
	else
		return (COMPLEX);
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
	if (flag == SIMPLE)
	{
		if (insertion_sort(stack_a, stack_b) == ERROR)
			return (ERROR);
	}
	else if (flag == MEDIUM)
	{
		if (chunk_sort(stack_a, stack_b) == ERROR)
			return (ERROR);
	}
	else if (flag == COMPLEX)
		radix_sort(stack_a, stack_b, lst_size(*stack_a));
	return (0);
}

/**
 * @brief Controll a safe exit by freeing both stacks
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param status The exit status.
 */
static void	free_both(t_stack **stack_a, t_stack **stack_b, int status)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (status == ERROR)
		ft_printf("Error\n");
	exit(status);
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	double	dis_index;
	int		flag;

	++argv;
	if (argc <= 1)
		return (0);
	flag = select_flag(&argv);
	list_a = first_node((const t_stack *)build_list(argv));
	if (!list_a)
		return (error());
	list_b = NULL;
	dis_index = compute_disorder(list_a);
	if (flag == ADAPTATIVE)
		flag = select_by_disorder(dis_index);
	if ((dis_index != 0) && (launch_algorithm(&list_a, &list_b, flag) == ERROR))
		free_both(&list_a, &list_b, ERROR);
	free_both(&list_a, &list_b, 0);
	return (0);
}
