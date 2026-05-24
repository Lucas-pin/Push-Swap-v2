/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:51:15 by jruiz-ag          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/05/20 20:09:59 by jruiz-ag         ###   ########.fr       */
=======
/*   Updated: 2026/05/23 23:44:51 by jruiz-ag         ###   ########.fr       */
>>>>>>> algorithms
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
<<<<<<< HEAD
	t_stack *first;
	t_stack *last;

=======
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || (lst_size(*stack) == 1))
		return ;
>>>>>>> algorithms
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
<<<<<<< HEAD
	if (!stack_a || !*stack_a || (lst_size(*stack_a) == 1))
		return ;
	rotate(stack_a);
=======
	rotate(stack_a);
	ft_printf("ra\n");
>>>>>>> algorithms
}

void	rb(t_stack **stack_b)
{
<<<<<<< HEAD
	if (!stack_b || !*stack_b || (lst_size(*stack_b) == 1))
		return ;
	rotate(stack_b);
=======
	rotate(stack_b);
	ft_printf("rb\n");
>>>>>>> algorithms
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
<<<<<<< HEAD
	ra(stack_a);
	rb(stack_b);
}
=======
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
>>>>>>> algorithms
