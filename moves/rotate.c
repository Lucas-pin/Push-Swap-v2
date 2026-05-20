/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:51:15 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/20 20:09:59 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	first = *stack;
	last = last_node(*stack);
	first->next->prev = NULL;
	*stack = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || (lst_size(*stack_a) == 1))
		return ;
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || (lst_size(*stack_b) == 1))
		return ;
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}