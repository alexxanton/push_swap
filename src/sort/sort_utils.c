/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:05:57 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/27 18:05:59 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	position_of(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
