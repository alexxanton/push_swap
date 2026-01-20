/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:26:07 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/13 15:43:02 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

int	get_next_move(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	return (1);
}

int	sort(t_list **a)
{
	t_list	*b = NULL;
	int		count;

	count = 0;
	while ((*a && !is_sorted(*a)) || b)
	{
		count += get_next_move(a, &b);
		break;
	}
	return (count);
}
