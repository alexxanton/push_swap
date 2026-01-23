/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:26:07 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/21 15:27:40 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

int	rotate_to_max(t_list **stack)
{
	int	max;
	int	count;

	count = 0;
	max = find_max(*stack);
	while ((*stack)->index != max)
	{
		rb(stack);
		count++;
	}
	return (count);
}

int	get_next_move(t_list **a, t_list **b)
{
	int	max;
	int	count;

	count = 0;
	max = find_max(*a);
	while (*a)
	{
		if ((*a)->index <= max)
		{
			pb(a, b);
			count++;
			if ((*b)->index < max / 2)
			{
				rb(b);
				count++;
			}
		}
		else
		{
			ra(a);
			count++;
		}
	}
	while (*b)
	{
		count += rotate_to_max(b);
		pa(b, a);
		count++;
	}
	return (count);
}

void	rank_nums(t_list *stack)
{
	t_list	*ptr;
	t_list	*next;
	int		count;

	ptr = stack;
	while (ptr)
	{
		count = 0;
		next = stack;
		while (next)
		{
			if (next->num < ptr->num)
				count++;
			next = next->next;
		}
		//printf("%d\n", count);
		ptr->index = count;
		ptr = ptr->next;
	}
}

int	sort(t_list **a)
{
	t_list	*b;
	int		count;

	b = NULL;
	count = 0;
	rank_nums(*a);
	while ((*a && !is_sorted(*a)) || b)
	{
		count = get_next_move(a, &b);
		//break ;
	}
	return (count);
}
