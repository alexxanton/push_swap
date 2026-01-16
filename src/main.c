/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:32:05 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/16 16:26:32 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	listi(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->num);
		list = list->next;
	}
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
		if (!args_contain_nums(split.arr))
		{
			free_array(split.arr);
			return (stack_error());
		}
		stack = create_stack(split.n, split.arr, 0);
	}
	else
	{
		if (!args_contain_nums(argv))
			return (stack_error());
		stack = create_stack(argc, argv, 1);
	}
	if (!stack)
		return (stack_error());
	//listi(stack);
	if (repeated_number(stack))
		printf("repeated\n");
	sort(&stack);
	//printf("sorted\n");
	list_clear(stack);
}
