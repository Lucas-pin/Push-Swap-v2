/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:28:56 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/17 13:28:56 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_only_digits(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		++str;
	}
	return (1);
}

static int	is_valid(const char *str)
{
	long	control;
	int		sign;

	sign = 1;
	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str == '0' && *(str + 1) != '\0')
		++str;
	if (!ft_only_digits(str) || (ft_strlen(str) > 10) || ft_strlen(str) < 1)
		return (0);
	control = 0;
	while (*str)
		control = control * 10 + (*(str++) - '0');
	control *= sign;
	if ((control < -2147483648) || (control > 2147483647))
		return (0);
	return (1);
}

static int	valid_args(char **argv)
{
	while (*argv)
	{
		if (!is_valid(*argv))
			return (0);
		++argv;
	}
	return (1);
}

static int	repeat_args(const t_stack *lst)
{
	t_stack		*i;
	t_stack		*j;

	i = first_node(lst);
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

t_stack	*build_list(char **argv)
{
	t_stack	*lst;
	t_stack	*new;

	lst = NULL;
	if (!valid_args(argv))
		return (NULL);
	while (*argv)
	{
		new = new_node(ft_atoi(*argv));
		if (!new)
		{
			free_stack(&lst);
			return (NULL);
		}
		add_node_back(&lst, new);
		++argv;
	}
	if (repeat_args(lst))
	{
		free_stack(&lst);
		return (NULL);
	}
	return (lst);
}
