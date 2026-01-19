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

void	stack_print(t_list *a, t_list *b)
{
	printf("- -\n");
	while (a)
	{
		printf("%d ", a->num);
		if (b)
			printf("%d\n ", b->num);
		a = a->next;
	}
}

void	sort(t_list **a)
{
	t_list	*b = NULL;

	printf("%p\n", a);
	printf("%p\n", &b);
	stack_print(*a, b);
	while (!is_sorted(*a))
	{
		ra(a);
		stack_print(*a, b);
		break;
	}
}
