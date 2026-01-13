/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:26:07 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/13 15:21:42 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

void	stack_print(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->num);
		list = list->next;
	}
}

void	sort(t_list **a)
{
	t_list	*b;

	while (!is_sorted(*a))
	{
		(void)b;
		ra(a);
		stack_print(*a);
		break;
	}
}
