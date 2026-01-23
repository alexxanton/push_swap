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

int stack_size(t_list *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int position_of(t_list *stack, int value)
{
    int pos;

    pos = 0;
    while (stack)
    {
        if (stack->index == value)
            return (pos);
        stack = stack->next;
        pos++;
    }
    return (-1); // should never happen in push_swap
}

int rotate_to_max(t_list **stack)
{
    int max;
    int pos;
    int size;
    int count;

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

//int	rotate_to_max(t_list **stack)
//{
//	int	max;
//	int	count;
//
//	count = 0;
//	max = find_max(*stack);
//	while ((*stack)->index != max)
//	{
//		rb(stack);
//		count++;
//	}
//	return (count);
//}

int	get_next_move(t_list **a, t_list **b)
{
	int	max;
	int	chunk_size;
	int	chunk_max;
	int	chunk_mid;
	int	count;

	int	pushed = 0;
	int	chunk_pushed = 0;

	count = 0;
	max = find_max(*a);
	chunk_size = 30;
	chunk_max = chunk_size - 1;
	if (chunk_max > max)
		chunk_max = max;
	chunk_mid = chunk_max - chunk_size / 2;
	while (*a)
	{
		if ((*a)->index <= chunk_max)
		{
			pb(a, b);
			pushed++;
			chunk_pushed++;
			count++;
			if ((*b)->index < chunk_mid)
			{
				rb(b);
				count++;
			}
			if (chunk_pushed == chunk_size)
			{
				chunk_pushed = 0;
				chunk_max += chunk_size;
				chunk_mid = chunk_max - chunk_size / 2;
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
