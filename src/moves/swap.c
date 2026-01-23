/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:36:26 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/13 15:33:34 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

void	swap(t_list **a)
{
	t_list	*swap;
	t_list	*stack;

	stack = *a;
	if (!stack || !stack->next)
		return ;
	swap = stack->next;
	stack->next = swap->next;
	swap->next = stack;
	*a = swap;
}

int	sa(t_list **a)
{
	swap(a);
	print_move("sa");
	return (1);
}

int	sb(t_list **stack)
{
	swap(stack);
	print_move("sb");
	return (1);
}

int	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	print_move("ss");
	return (1);
}
