/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:19:30 by aanton-a          #+#    #+#             */
/*   Updated: 2025/12/19 12:50:51 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

t_list	*create_stack(int argc, char **argv, int start)
{
	t_list	*stack;
	t_list	*next;
	int		i;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	next = stack;
	i = start;
	while (i < argc)
	{
		next->num = ft_atoi(argv[i]);
		next->next = NULL;
		if (i < argc - 1)
			next->next = malloc(sizeof(t_list));
		if (!next->next)
			break ;
		next = next->next;
		i++;
	}
	if (start == 0)
		free_array(argv);
	return (stack);
}
