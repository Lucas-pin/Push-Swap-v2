/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:39:06 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/23 12:39:06 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Find the minimum value in the stack.
 * but can search place for instance the second less
 * @param stack The stack to search
 * @param relative_pos which relative minimum want (second, third...)
 * @return The minimum value with relative_pos
 */
static int	min_value(t_stack *stack, int relative_pos)
{
	t_stack	*init;
	int		min;
	int		min_actual;
	int		actual_pos;

	actual_pos = -1;
	min_actual = INT_MAX;
	min = INT_MIN;
	init = stack;
	while (actual_pos < relative_pos)
	{
		stack = init;
		min_actual = INT_MAX;
		while (stack)
		{
			if ((stack->value < min_actual) && (stack->value > min))
				min_actual = stack->value;
			stack = stack->next;
		}
		min = min_actual;
		actual_pos++;
	}
	return (min);
}

/**
 * @brief Find the n minimum numbers in stack which are part of the chunk.
 * @param stack The stack which is evaluated
 * @param n_in_chunk The amount of minimum numbers that are required
 * @return An array of numbers with the which the numbers of the actual chunk.
 */
static int	*extract_chunk(t_stack *stack, int n_in_chunk)
{
	int	*chunk;
	int	n_inserted;

	if (n_in_chunk < 1)
		return (NULL);
	chunk = ft_calloc(n_in_chunk, sizeof(int));
	if (!chunk)
		return (NULL);
	n_inserted = 0;
	while (n_inserted < n_in_chunk)
	{
		chunk[n_inserted] = min_value(stack, n_inserted);
		n_inserted++;
	}
	return (chunk);
}

/**
 * @brief Moves the n minimum numbers (chunk) from stack a to stack b.
 * @param stack_a A pointer to any node of stack a.
 * @param stack_b A pointer to any node of stack b.
 * @param len_chunk The amount of minimum numbers that are going to be moved.
 * @return 0 if the movement have been correct, ERROR if cant be possible.
 */
static int	mv_chunk(t_stack **stack_a, t_stack **stack_b, int len_chunk)
{
	int	moved;
	int	*chunk;

	moved = 0;
	chunk = extract_chunk(*stack_a, len_chunk);
	if (!chunk)
		return (ERROR);
	while (moved < len_chunk)
	{
		if (ft_in_array((*stack_a)->value, chunk, len_chunk))
		{
			pb(stack_a, stack_b);
			++moved;
		}
		else
			ra(stack_a);
	}
	free(chunk);
	return (0);
}

/**
 * @brief Moves all of nodes from stack a to stack b chunk by chunk.
 * @param stack_a A pointer to any node of stack a.
 * @param stack_b A pointer to any node of stack b.
 * @return 0 if all the movement have been correct, ERROR if cant be possible.
 */
static int	pb_by_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int	n;
	int	total_chunks;
	int	moved_chunks;

	n = lst_size(*stack_a);
	total_chunks = ft_sqrt(n);
	moved_chunks = 0;
	while (moved_chunks < total_chunks)
	{
		if (mv_chunk(stack_a, stack_b, total_chunks) == ERROR)
			return (ERROR);
		++moved_chunks;
	}
	while (*stack_a)
		pb(stack_a, stack_b);
	return (0);
}

int	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	if (!stack_a || !stack_b)
		return (ERROR);
	if (pb_by_chunks(stack_a, stack_b) == ERROR)
		return (ERROR);
	while (*stack_b)
	{
		pos = pos_of_value(*stack_b, max_value(*stack_b));
		rotate_stack(stack_b, pos);
		pa(stack_a, stack_b);
	}
	return (0);
}
