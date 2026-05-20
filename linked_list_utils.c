/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:29:07 by lupin             #+#    #+#             */
/*   Updated: 2026/05/20 23:20:40 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(const t_stack *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_stack	*last_node(const t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return ((t_stack *)lst);
}

t_stack	*first_node(const t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return ((t_stack *)lst);
}

void	print_list(const t_stack *lst)
{
	if (!lst)
	{
		ft_printf("Empty list\n");
		return ;
	}
	ft_printf("[DBEUG] stack values: \n");
	while (lst)
	{
		ft_printf("%i", lst->value);
		if (lst->next)
			ft_printf(", ");
		lst = lst->next;
	}
	ft_printf("\n");
}
