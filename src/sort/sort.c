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

int	sort_three_nums(t_list *stack)
{
	int		nums[3];
	int		i;

	i = 0;
	while (i < 3)
	{
		nums[i] = stack->num;
		if (stack->next)
			stack = stack->next;
		i++;
	}
	if (nums[0] > nums[1] && nums[1] < nums[2])
		ra(&stack);
	else if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		ra(&stack);
		sa(&stack);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] < nums[2])
	{
		sa(&stack);
		ra(&stack);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] > nums[2])
	{
		rra(&stack);
	}
	return (1);
}

int	get_next_move(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	return (1);
}

int	sort(t_list **a)
{
	t_list	*b;
	int		count;

	b = NULL;
	count = 0;
	return (sort_three_nums(*a));
	while ((*a && !is_sorted(*a)) || b)
	{
		count += get_next_move(a, &b);
		break ;
	}
	return (count);
}
