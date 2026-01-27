/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:36:08 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/27 18:06:59 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_list **from, t_list **to)
{
	t_list	*stack;

	if (!*from)
		return ;
	stack = *from;
	*from = (*from)->next;
	if (!*to)
	{
		*to = stack;
		(*to)->next = NULL;
	}
	else
	{
		stack->next = *to;
		*to = stack;
	}
}

int	pa(t_list **a, t_list **b)
{
	push(a, b);
	print_move("pa");
	return (1);
}

int	pb(t_list **a, t_list **b)
{
	push(a, b);
	print_move("pb");
	return (1);
}
