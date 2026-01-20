/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:30:48 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/16 17:02:38 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_split
{
	int		n;
	char	**arr;
}	t_split;

void	free_array(char **argv);
t_list	*create_stack(int argc, char **argv, int start);
bool	is_sorted(t_list *list);
bool	repeated_number(t_list *list);
bool	validate_args(char **args, int start);

// Utils
t_split	ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	list_clear(t_list *list);

void	sa(t_list **a);
void	sb(t_list **stack);
void	ss(t_list **a, t_list **b);

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **a, t_list **b);

void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **a, t_list **b);

int		sort(t_list **a);
void	print_move(char *move);

#endif
