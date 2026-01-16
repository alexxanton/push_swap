/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:42:34 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/16 17:08:53 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	isnum(char c)
{
	if (c)
		return (c >= '0' && c <= '9');
	return (false);
}

bool	validate_args(char **args, int start)
{
	int		i;
	int		j;
	int		len;
	char	c;

	i = start;
	while (args[i])
	{
		j = 0;
		len = ft_strlen(args[i]);
		while (args[i][j])
		{
			c = args[i][j];
			if ((j == 0 && !isnum(c)) && (c == '-' || c == '+'))
			{
				if (!isnum(args[i][j + 1]))
					return false;
			}
			else if (!isnum(c))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
