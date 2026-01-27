/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:30:48 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/27 16:09:45 by aanton-a         ###   ########.fr       */
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
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_chunk
{
	int	size;
	int	max;
	int	mid;
	int	pushed;
}	t_chunk;

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

int		find_max(t_list *stack);
void	list_clear(t_list *list);

int		sa(t_list **a);
int		sb(t_list **stack);
int		ss(t_list **a, t_list **b);

int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);

int		ra(t_list **stack);
int		rb(t_list **stack);
int		rr(t_list **a, t_list **b);

int		rra(t_list **stack);
int		rrb(t_list **stack);
int		rrr(t_list **a, t_list **b);

int		sort(t_list **a);
void	print_move(char *move);
int		stack_size(t_list *stack);
int		position_of(t_list *stack, int value);
int		sort_small_stack(t_list **a, t_list **b, int len);
int		rotate_to_target(t_list **stack, int target);

#endif
