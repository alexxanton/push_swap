/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:55:13 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/27 18:23:34 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	hardcoded_moves(t_list **stack, int nums[3])
{
	if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		ra(stack);
		sa(stack);
		return (2);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] > nums[2])
		rra(stack);
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] < nums[2])
	{
		sa(stack);
		ra(stack);
		return (2);
	}
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] > nums[2])
		ra(stack);
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] < nums[2])
		sa(stack);
	return (1);
}

int	sort_three_nums(t_list **stack)
{
	int		nums[3];
	int		i;
	t_list	*ptr;

	ptr = *stack;
	i = 0;
	while (i < 3)
	{
		nums[i] = ptr->num;
		if (ptr->next)
			ptr = ptr->next;
		i++;
	}
	return (hardcoded_moves(stack, nums));
}

int	rotate_to_target(t_list **stack, int target)
{
	int	pos;
	int	size;
	int	count;

	pos = position_of(*stack, target);
	size = stack_size(*stack);
	count = 0;
	if (pos <= size / 2)
		while ((*stack)->index != target)
			count += ra(stack);
	else
		while ((*stack)->index != target)
			count += rra(stack);
	return (count);
}

int	sort_small_stack(t_list **a, t_list **b, int len)
{
	int	count;

	count = 0;
	if (len == 2)
		return (sa(a));
	if (len == 3)
		return (sort_three_nums(a));
	count += rotate_to_target(a, 0);
	pb(a, b);
	if (len == 5)
	{
		count += rotate_to_target(a, 1);
		pb(a, b);
		count += 2;
	}
	count += sort_three_nums(a);
	pa(b, a);
	if (len == 5)
		pa(b, a);
	return (count + 2);
}
