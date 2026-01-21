/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:59:53 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/21 14:15:44 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	is_sorted(t_list *list)
{
	t_list	*next;

	if (!list->next)
		return (true);
	while (list)
	{
		next = list->next;
		if (list->num > next->num)
			return (false);
		if (next->next)
			list = next;
		else
			return (true);
	}
	return (true);
}

bool	repeated_number(t_list *list)
{
	t_list	*sub;
	int		num;

	while (list)
	{
		num = list->num;
		sub = list->next;
		while (sub)
		{
			if (sub->num == num)
				return (true);
			sub = sub->next;
		}
		list = list->next;
	}
	return (false);
}
