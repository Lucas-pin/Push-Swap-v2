/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:54:37 by lupin             #+#    #+#             */
/*   Updated: 2026/05/22 00:14:42 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*compute_disorder(t_stack *stack, int *disorder)
{
	t_stack	*aux;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!stack)
		return (int[]){ERROR, ERROR};
	while (stack)
	{
		aux = stack->next;
		while (aux)
		{
			total_pairs++;
			if (stack->value > aux->value)
				mistakes++;
			aux = aux->next;
		}
		stack = stack->next;
	}
	disorder[0] = mistakes / total_pairs;
	disorder[1] = mistakes % total_pairs;
	return (disorder);
}
