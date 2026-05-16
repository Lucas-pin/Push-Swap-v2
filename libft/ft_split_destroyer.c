/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_destroyer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:25:32 by lupin             #+#    #+#             */
/*   Updated: 2026/05/16 19:25:36 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_split_destroyer(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		ft_destroyer(split + i);
		i++;
	}
	free (split[i]);
	return (NULL);
}
