/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:36:20 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/13 17:46:53 by aanton-a         ###   ########.fr       */
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

int	rra(t_list **stack)
{
	reverse(stack);
	print_move("rra");
	return (1);
}

int	rrb(t_list **stack)
{
	reverse(stack);
	print_move("rrb");
	return (1);
}

int	rrr(t_list **a, t_list **b)
{
	reverse(a);
	reverse(b);
	print_move("rrr");
	return (1);
}
