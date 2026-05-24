/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:51:15 by jruiz-ag          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/05/20 20:06:32 by jruiz-ag         ###   ########.fr       */
=======
/*   Updated: 2026/05/23 23:44:23 by jruiz-ag         ###   ########.fr       */
>>>>>>> algorithms
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack **stack)
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
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
<<<<<<< HEAD
	if (!stack_a || !*stack_a || (lst_size(*stack_a) == 1))
		return ;
	rev_rotate(stack_a);
=======
	rev_rotate(stack_a);
	ft_printf("rra\n");
>>>>>>> algorithms
}

void	rrb(t_stack **stack_b)
{
<<<<<<< HEAD
	if (!stack_b || !*stack_b || (lst_size(*stack_b) == 1))
		return ;
	rev_rotate(stack_b);
=======
	rev_rotate(stack_b);
	ft_printf("rrb\n");
>>>>>>> algorithms
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
<<<<<<< HEAD
	rra(stack_a);
	rrb(stack_b);
}
=======
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
>>>>>>> algorithms
