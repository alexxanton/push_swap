/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:55:13 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/27 17:14:29 by aanton-a         ###   ########.fr       */
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
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] < nums[2])
	{
		sa(stack);
		ra(stack);
		return (2);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] > nums[2])
		rra(stack);
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

int	sort_small_stack(t_list **a, t_list **b, int len)
{
	if (len == 2)
		return (sa(a));
	if (len == 3)
		return (sort_three_nums(a));
	rotate_to_target(a, 0);
	pb(a, b);
	if (len == 5)
	{
		rotate_to_target(a, 1);
		pb(a, b);
	}
	sort_three_nums(a);
	pa(b, a);
	pa(b, a);
	return (0);
}
