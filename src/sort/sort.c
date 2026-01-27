/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:26:07 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/27 16:08:55 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/push_swap.h>

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
		ptr->index = count;
		ptr = ptr->next;
	}
}

int	rotate_to_max(t_list **stack)
{
	int	max;
	int	pos;
	int	size;
	int	count;

	max = find_max(*stack);
	pos = position_of(*stack, max);
	size = stack_size(*stack);
	count = 0;
	if (pos <= size / 2)
		while ((*stack)->index != max)
			count += rb(stack);
	else
		while ((*stack)->index != max)
			count += rrb(stack);
	return (count);
}

int	rotate_and_push(t_list **a, t_list **b)
{
	int	count;

	count = 0;
	while (*b)
	{
		count += rotate_to_max(b);
		count += pa(b, a);
	}
	return (count);
}

int	chunk_sort(t_list **a, t_list **b, t_chunk chunk)
{
	int	count;

	count = 0;
	while (*a)
	{
		if ((*a)->index <= chunk.max)
		{
			count += pb(a, b);
			chunk.pushed++;
			if ((*b)->index < chunk.mid)
				count += rb(b);
			if (chunk.pushed == chunk.size)
			{
				chunk.pushed = 0;
				chunk.max += chunk.size;
				chunk.mid = chunk.max - chunk.size / 2;
			}
		}
		else
			count += ra(a);
	}
	count += rotate_and_push(a, b);
	return (count);
}

int	sort(t_list **a)
{
	t_list	*b;
	t_chunk	chunk;
	int		count;
	int		len;

	len = stack_size(*a);
	b = NULL;
	count = 0;
	rank_nums(*a);
	if (len <= 5)
	{
		sort_small_stack(a, &b, len);
		return (count);
	}
	if (len <= 100)
		chunk.size = 15;
	else
		chunk.size = 30;
	chunk.max = chunk.size;
	chunk.mid = chunk.max - chunk.size / 2;
	chunk.pushed = 0;
	if (!is_sorted(*a))
		count = chunk_sort(a, &b, chunk);
	return (count);
}
