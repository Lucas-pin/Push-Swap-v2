/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:50:26 by lupin             #+#    #+#             */
/*   Updated: 2026/05/16 20:51:01 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(long content)
{
	t_stack	*nodo;

	nodo = NULL;
	nodo = ft_calloc(1, sizeof(t_stack));
	if (nodo == NULL)
		return (NULL);
	nodo->next = NULL;
	nodo->prev = NULL;
	return (nodo);
}

void	add_node_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (!new)
		return ;
	else if (!*lst)
		*lst = new_node(-1);
	else
	{
		first = first_node(*lst);
		first->prev = new;
		new->next = first;
		*lst = new;
	}
}

void	add_node_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	else if (!*lst)
		*lst = new_node(-1);
	else
	{
		last = last_node(*lst);
		last->next = new;
		new->prev = last;
	}
}