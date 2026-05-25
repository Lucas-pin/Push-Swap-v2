/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 00:06:11 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/25 22:36:38 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Find the maximum amount of bits needed to represent any num.
 * @param stack The stack which is going to be control.
 * @return An integer with the maximum bits required.
 */
static int	find_max_bits(t_stack *stack)
{
	int	max_bits;
	int	n_bits;

	max_bits = 0;
	while (stack)
	{
		n_bits = ft_cont_bits(stack->index);
		if (n_bits > max_bits)
			max_bits = n_bits;
		stack = stack->next;
	}
	return (max_bits);
}

/**
 * @brief Do an iteration of the radix algorithm controlling the idx bit.
 * @param stack_a Pointer to any node of stack a.
 * @param stack_b Pointer to any node of stack b.
 * @param idx_bit The position of the bit which is going to evaluate this iter.
 * @param size The size of the list.
 */
static void	iter(t_stack **stack_a, t_stack **stack_b, int idx_bit, int size)
{
	int	cont;
	int	bit_value;

	cont = 0;
	while (cont < size)
	{
		bit_value = ft_bit_value((*stack_a)->index, idx_bit);
		if (bit_value == 0)
			orchestor(stack_a, stack_b, 0, PB);
		else
			orchestor(stack_a, stack_b, 0, RA);
		++cont;
	}
	while (*stack_b)
		orchestor(stack_a, stack_b, 0, PA);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		max_length;
	int		idx_bit;

	assign_index(stack_a);
	max_length = find_max_bits(*stack_a);
	idx_bit = 0;
	while (idx_bit < max_length)
	{
		iter(stack_a, stack_b, idx_bit, size);
		++idx_bit;
	}
	orchestor(stack_a, stack_b, PRINT, -1);
}
