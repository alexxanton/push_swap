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

void	print_move(char *move)
{
	write(1, move, ft_strlen(move));
	write(1, "\n", 1);
}

void	sort(t_list **a)
{
	t_list	*b = NULL;
	char	*move;

	while ((*a && !is_sorted(*a)) || b)
	{
		move = ra(a);
		print_move(move);
		move = rra(a);
		print_move(move);
		break;
	}
}
