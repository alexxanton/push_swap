/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:36:26 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/08 16:59:28 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

char	*sa(t_list *stack)
{
	t_list	*swap;

	if (!stack && !stack->next)
		return ("");
	swap = stack;
	stack->next = swap;
	stack = stack->next;
	return ("sa");
}

char	*sb(t_list *b)
{
	if (sa(b))
		return ("sb");
	return ("");
}

char	*ss(t_list *a, t_list *b)
{
	if (sa(a) && sa(b))
		return ("ss");
	return ("");
}
