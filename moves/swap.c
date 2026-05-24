/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:17:41 by jruiz-ag          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/05/20 19:35:19 by jruiz-ag         ###   ########.fr       */
=======
/*   Updated: 2026/05/23 23:45:21 by jruiz-ag         ###   ########.fr       */
>>>>>>> algorithms
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
<<<<<<< HEAD
	t_stack *first;
	t_stack *second;

=======
	t_stack	*first;
	t_stack	*second;

	if (!stack || (lst_size(*stack) <= 1))
		return ;
>>>>>>> algorithms
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
<<<<<<< HEAD
	if (!stack_a)
		return ;
	if(lst_size(*stack_a) <= 1)
		return ;
	swap(stack_a);
=======
	swap(stack_a);
	ft_printf("sa\n");
>>>>>>> algorithms
}

void	sb(t_stack **stack_b)
{
<<<<<<< HEAD
	if (!stack_b)
		return ;
	if(lst_size(*stack_b) <= 1)
		return ;
	swap(stack_b);
=======
	swap(stack_b);
	ft_printf("sb\n");
>>>>>>> algorithms
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
<<<<<<< HEAD
	sa(stack_a);
	sb(stack_b);
}
=======
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
>>>>>>> algorithms
