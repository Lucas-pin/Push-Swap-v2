/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 22:19:28 by lupin             #+#    #+#             */
/*   Updated: 2026/05/21 01:05:16 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_pos(t_stack *stack, int value)
{
	int	pos;
	int	index;
	int	prev_value;

	index = 0;
	prev_value = -2147483648;
	if (!stack)
		return (-1);
	pos = -1;
	while (stack)
	{
		if (value > stack->value && prev_value <= stack->value)
		{
			prev_value = stack->value;
			pos = index;
		}
		index++;
		stack = stack->next;
	}
	return (pos);
}

static int	find_max_pos(t_stack *stack, int value)
{
	int	pos;
	int	index;
	int	prev_value;

	index = 0;
	prev_value = -2147483648;
	if (!stack)
		return (-1);
	pos = -1;
	while (stack)
	{
		if (value < stack->value && prev_value <= stack->value)
		{
			prev_value = stack->value;
			pos = index;
		}
		index++;
		stack = stack->next;
	}
	return (pos);
}

static int	max_value(t_stack *stack)
{
	int	max;

	max = -2147483648;
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

	size = lst_size(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(stack);
	}
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	max;

	pb(stack_a, stack_b);
	while (*stack_a)
	{
		pos = find_min_pos(*stack_b, (*stack_a)->value);
		if (pos == -1)
			pos = find_max_pos(*stack_b, (*stack_a)->value);
		if (pos == -1)
			return ;
		rotate_stack(stack_b, pos);
		pb(stack_a, stack_b);
	}
	rotate_stack(stack_b, find_min_pos(*stack_b, max_value(*stack_b) + 1));
	while (*stack_b)
		pa(stack_a, stack_b);
}
