/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:42:34 by aanton-a          #+#    #+#             */
/*   Updated: 2025/12/19 13:14:47 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	args_contain_nums(char **args)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			c = args[i][j];
			if ((c < '0' || c > '9') && c != '-')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
