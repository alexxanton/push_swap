/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:36:08 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/09 14:32:45 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

void	push(t_list **from, t_list **to)
{
	t_list	*stack;

	if (!*from)
		return ;
	stack = *from;
	*from = (*from)->next;
	if (!to) // TODO: figure out if i have to use (!*to) instead
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

char	*pa(t_list **a, t_list **b)
{
	push(a, b);
	return ("pa");
}

char	*pb(t_list **a, t_list **b)
{
	push(a, b);
	return ("pb");
}
