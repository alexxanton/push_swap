/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:40:17 by aanton-a          #+#    #+#             */
/*   Updated: 2026/01/16 16:14:22 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	count_words(char const *s, char c)
{
	int	new_word;
	int	count;

	new_word = 0;
	count = 0;
	while (*s)
	{
		if ((*s < '0' || *s > '9') && (*s != '-' && *s != ' '))
			return (-1);
		if (*s != c && !new_word)
		{
			count++;
			new_word = 1;
		}
		if (*s == c)
		{
			new_word = 0;
		}
		s++;
	}
	return (count);
}

static int	free_array_with_err(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static int	allocate_array(char **arr, char const *s, char c)
{
	int	i;
	int	pos;
	int	idx;

	i = 0;
	idx = 0;
	pos = -1;
	while (s[i])
	{
		if (s[i] != c && pos < 0)
			pos = i;
		if ((s[i + 1] == c || !s[i + 1]) && pos >= 0)
		{
			arr[idx] = ft_substr(s, pos, i - pos + 1);
			if (!arr[idx])
				return (free_array_with_err(arr));
			pos = -1;
			idx++;
		}
		i++;
	}
	arr[idx] = NULL;
	return (1);
}

t_split	ft_split(char const *s, char c)
{
	int		count;
	char	**arr;
	t_split	split;

	count = count_words(s, c);
	if (count == -1)
	{
		split.n = 0;
		split.arr = NULL;
		return (split);
	}
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr || !allocate_array(arr, s, c))
	{
		split.n = 0;
		split.arr = NULL;
		return (split);
	}
	split.n = count;
	split.arr = arr;
	return (split);
}
