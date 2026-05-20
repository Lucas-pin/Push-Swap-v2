/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:11:11 by lupin             #+#    #+#             */
/*   Updated: 2026/05/20 19:07:23 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*push_isolate(t_stack **lst)
{
	t_stack	*aux;

	if (!lst || !*lst)
		return (NULL);
	aux = *lst;
	*lst = aux->next;
	if (*lst)
		(*lst)->prev = NULL;
	aux->next = NULL;
	return (aux);
}

static void	push(t_stack **dst, t_stack **src)
{
	if (!dst || !src)
		return ;
	add_node_front(dst, push_isolate(src));
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return ;
	push(stack_a, stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a)
		return ;
	push(stack_b, stack_a);
}
