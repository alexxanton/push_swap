/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:36:20 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/13 16:05:12 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

void	reverse(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*last_prev;

	first = *stack;
	last = *stack;
	if (!*stack || !(*stack)->next)
		return ;
	while (last->next)
	{
		last_prev = last;
		last = last->next;
	}
	last->next = first;
	last_prev->next = NULL;
	*stack = last;
}

char	*ra(t_list **stack)
{
	reverse(stack);
	return ("rra");
}

char	*rb(t_list **stack)
{
	reverse(stack);
	return ("rrb");
}

char	*rr(t_list **a, t_list **b)
{
	reverse(a);
	reverse(b);
	return ("rrr");
}
