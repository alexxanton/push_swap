/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:23:16 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/21 14:12:45 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	list_clear(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

int	find_max(t_list *stack)
{
	int		max;

	max = stack->index;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_list *stack)
{
	t_list	*next;
	int		min;

	next = stack;
	min = next->num;
	while (stack)
	{
		next = stack->next;
		if (min > next->num)
			min = next->num;
		stack = next;
	}
	return (min);
}
