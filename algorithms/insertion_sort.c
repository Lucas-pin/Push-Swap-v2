/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 22:19:28 by lupin             #+#    #+#             */
/*   Updated: 2026/05/23 14:30:45 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Find the position into stack where value 
 * should be inserted to keep the order
 * @param stack The stack to search
 * @param value The value to insert
 * @param order The order to keep (ASC or DESC)
 * @return The position where value should be inserted,
 * or -1 if it can't be inserted
 */
static int	find_pos(t_stack *stack, int value, t_order order)
{
	int	pos;
	int	index;
	int	prev;

	index = 0;
	prev = INT_MIN;
	if (!stack)
		return (ERROR);
	pos = ERROR;
	while (stack)
	{
		if ((value > stack->value && prev <= stack->value && order == DESC)
			|| (value < stack->value && prev <= stack->value && order == ASC))
		{
			prev = stack->value;
			pos = index;
		}
		index++;
		stack = stack->next;
	}
	return (pos);
}

int	max_value(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	rotate_stack(t_stack **stack, int pos)
{
	int	size;
	int	count;

	size = lst_size(*stack);
	if (pos <= size / 2)
	{
		count = pos;
		while (count-- > 0)
			rb(stack);
	}
	else
	{
		count = size - pos;
		while (count-- > 0)
			rrb(stack);
	}
}

int	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	higher_pos;

	pb(stack_a, stack_b);
	while (*stack_a)
	{
		pos = find_pos(*stack_b, (*stack_a)->value, DESC);
		if (pos == ERROR)
			pos = find_pos(*stack_b, (*stack_a)->value, ASC);
		if (pos == ERROR)
			return (ERROR);
		rotate_stack(stack_b, pos);
		pb(stack_a, stack_b);
	}
	higher_pos = pos_of_value(*stack_b, max_value(*stack_b));
	rotate_stack(stack_b, higher_pos);
	while (*stack_b)
		pa(stack_a, stack_b);
	return (0);
}
