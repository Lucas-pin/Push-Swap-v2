/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:17:41 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/20 19:35:19 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	if(lst_size(*stack_a) <= 1)
		return ;
	swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	if (!stack_b)
		return ;
	if(lst_size(*stack_b) <= 1)
		return ;
	swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}