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

static int	valid_args(const char **argv)
{
	while (*argv)
	{
		if (!is_valid(*argv))
			return (0);
		++argv;
	}
	return (1);
}

static int	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
		++cont;
	return (cont);
}

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

	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		++str;
	if (*str == '-' || *str == '+')
		++str;
	if (!ft_only_digits(str) || (ft_strlen(str) > 10))
		return (0);
	control = 0;
	while (*str)
	{
		control = control * 10 + (*str - '0');
		++str;
	}
	if ((control < -2147483648) || (control > 2147483647))
		return (0);
	return (1);
}

t_stack	*build_list(char **argv)
{
	t_stack	*lst;
	t_stack	*new;

	if (!is_valid(argv))
		return (NULL);
	while (*argv)
	{
		new = new_node(ft_atoi(*argv));
		if (!new)
		{
			free(lst);
			return (NULL);
		}
		add_node_back(&lst, new);
		++argv;
	}
	return (lst);
}
