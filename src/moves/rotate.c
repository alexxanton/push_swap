/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:36:20 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/13 18:32:12 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = *stack;
	if (!*stack || !(*stack)->next)
		return ;
	while (last->next)
		last = last->next;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

char	*ra(t_list **stack)
{
	rotate(stack);
	return ("ra");
}

char	*rb(t_list **stack)
{
	rotate(stack);
	return ("rb");
}

char	*rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	return ("rr");
}
