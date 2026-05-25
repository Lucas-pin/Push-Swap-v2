/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:14:24 by lupin             #+#    #+#             */
/*   Updated: 2026/05/25 22:44:24 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*get_func(t_move move)
{
	if (move == PA)
		return ((void *)pa);
	else if (move == PB)
		return ((void *)pb);
	else if (move == SA)
		return ((void *)sa);
	else if (move == SB)
		return ((void *)sb);
	else if (move == SS)
		return ((void *)ss);
	else if (move == RA)
		return ((void *)ra);
	else if (move == RB)
		return ((void *)rb);
	else if (move == RR)
		return ((void *)rr);
	else if (move == RRA)
		return ((void *)rra);
	else if (move == RRB)
		return ((void *)rrb);
	else if (move == RRR)
		return ((void *)rrr);
	return (NULL);
}

void	print_benchmark(int *moves_count)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(moves_count[SA], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(moves_count[SB], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(moves_count[SS], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(moves_count[PA], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(moves_count[PB], 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(moves_count[RA], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(moves_count[RB], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(moves_count[RR], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(moves_count[RRA], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(moves_count[RRB], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(moves_count[RRR], 2);
	ft_putstr_fd("\n[bench] total moves: ", 2);
	ft_putnbr_fd(moves_count[11], 2);
	ft_putstr_fd("\n", 2);
}

void	orchestor(t_stack **stack_a, t_stack **stack_b, int flag, t_move move)
{
	static int	moves_count[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	void		(*func)(t_stack **, t_stack **);

	func = NULL;
	if (flag == BENCH)
		moves_count[12]++;
	else if (flag != PRINT)
		func = get_func(move);
	if (func)
	{
		func(stack_a, stack_b);
		if (moves_count[12] != 0)
		{
			moves_count[move]++;
			moves_count[TOTAL]++;
		}
	}
	if (flag == PRINT && moves_count[12] != 0)
		print_benchmark(moves_count);
}

