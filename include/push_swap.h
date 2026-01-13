/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:30:48 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/13 15:03:54 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

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

t_list	*create_stack(int argc, char **argv, int start);
bool	is_sorted(t_list *list);
bool	repeated_number(t_list *list);
bool	args_contain_nums(char **args);

// Utils
t_split	ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	list_clear(t_list *list);

char	*sa(t_list **a);
char	*pb(t_list **a, t_list **b);
char	*pa(t_list **a, t_list **b);
char	*ra(t_list **stack);
void	sort(t_list **a);

#endif
