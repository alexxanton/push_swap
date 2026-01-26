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

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	position_of(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int rotate_to_max(t_list **stack)
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
			rb(stack), count++;
	else
		while ((*stack)->index != max)
			rrb(stack), count++;
	return (count);
}

int	chunk_sort(t_list **a, t_list **b, t_chunk chunk)
{
	int	count;
	int	pushed;
	int	chunk_pushed;

	count = 0;
	pushed = 0;
	chunk_pushed = 0;
	while (*a)
	{
		if ((*a)->index <= chunk.max)
		{
			count += pb(a, b);
			pushed++;
			chunk_pushed++;
			if ((*b)->index < chunk.mid)
				count += rb(b);
			if (chunk_pushed == chunk.size)
			{
				chunk_pushed = 0;
				chunk.max += chunk.size;
				chunk.mid = chunk.max - chunk.size / 2;
			}
		}
		else
			count += ra(a);
	}
	while (*b)
	{
		count += rotate_to_max(b);
		count += pa(b, a);
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
		ptr->index = count;
		ptr = ptr->next;
	}
}

int	sort(t_list **a)
{
	t_list	*b;
	t_chunk	chunk;
	int		count;

	//max = find_max(*a);
	//if (chunk_max > max)
	//	chunk_max = max;
	b = NULL;
	count = 0;
	rank_nums(*a);
	chunk.size = 30;
	chunk.max = chunk.size - 1;
	chunk.mid = chunk.max - chunk.size / 2;
	while ((*a && !is_sorted(*a)) || b)
	{
		count = chunk_sort(a, &b, chunk);
	}
	return (count);
}
