/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:51:15 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/20 19:57:11 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	first = *stack;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || (lst_size(*stack_a) == 1))
		return ;
	rev_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || (lst_size(*stack_b) == 1))
		return ;
	rev_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}