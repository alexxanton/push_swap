/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:32:05 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/27 17:53:45 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	solve(t_list *stack)
{
	if (!stack)
		return (stack_error());
	if (repeated_number(stack))
		return (stack_error());
	sort(&stack);
	list_clear(stack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_split	split;

	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split.arr)
			return (stack_error());
		if (!validate_args(split.arr, 0))
		{
			free_array(split.arr);
			return (stack_error());
		}
		stack = create_stack(split.n, split.arr, 0);
	}
	else
	{
		if (!validate_args(argv, 1))
			return (stack_error());
		stack = create_stack(argc, argv, 1);
	}
	return (solve(stack));
}
