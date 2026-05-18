/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:11:11 by lupin             #+#    #+#             */
/*   Updated: 2026/05/18 21:39:24 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*isolate(t_stack **lst)
{
	t_stack	*aux;

	if (!lst || !*lst)
		return (NULL);
	aux = *lst;
	if (aux->prev)
		aux->prev->next = aux->next;
	if (aux->next)
		aux->next->prev = aux->prev;
	aux->prev = NULL;
	aux->next = NULL;
	return (aux);
}

static void	push(t_stack **dst, t_stack **src)
{
	if (!dst || !src)
		return ;
	add_node_front(dst, isolate(src));
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (!stack_b)
		return ;
	first_a = first_node(stack_a);
	first_b = first_node(stack_b);
	push(&stack_a, &stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (!stack_a)
		return ;
	first_a = first_node(stack_a);
	first_b = first_node(stack_b);
	push(&stack_b, &stack_a);
}
