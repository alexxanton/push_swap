/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:19:30 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/16 16:10:19 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	parse_num(t_list *stack, int argc, char **argv, int start)
{
	t_list	*next;
	long	num;
	int		i;

	next = stack;
	i = start;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		next->next = NULL;
		if (num > INT_MAX || num < INT_MIN)
		{
			list_clear(stack);
			return (false);
		}
		next->num = (int)num;
		if (i < argc - 1)
			next->next = malloc(sizeof(t_list));
		if (!next->next)
			break ; // TODO: return (null) causes memleak
		next = next->next;
		i++;
	}
	return (true);
}

t_list	*create_stack(int argc, char **argv, int start)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	if (!parse_num(stack, argc, argv, start))
		return (NULL);
	if (start == 0)
		free_array(argv);
	return (stack);
}
