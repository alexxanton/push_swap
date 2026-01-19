#include "test.h"

void	print_line()
{
	printf("+");
	for (int i = 0; i < 9; i++)
		printf("-");
	printf("+");
	for (int i = 0; i < 9; i++)
		printf("-");
	printf("+\n");
}

void	print(t_list *a, t_list *b)
{
	int	max = 0;
	print_line();
	while ((a || b) && ++max)
	{
		if (max > 10 && max < stack_len - 10)
		{
			if (max == 11)
				printf("|        ...        |\n");
		}
		else
		{
			if (a)
				printf("|%9d|", a->num);
			else
				printf("|         |");
			if (b)
				printf("%9d|\n", b->num);
			else
				printf("         |\n");
		}
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	print_line();
}

void	instructions(t_list **a, t_list **b)
{
	char	str[4] = "";

	printf("Stack len: %d\n", stack_len);
	print(*a, *b);
	while (!is_sorted(*a))
	{
		read(1, str, 4);
		if (strncmp(str, "sa", 2) == 0)
			sa(a);
		else if (strncmp(str, "sb", 2) == 0)
			sb(b);
		else if (strncmp(str, "pa", 2) == 0)
			pa(b, a);
		else if (strncmp(str, "pb", 2) == 0)
			pb(a, b);
		else if (strncmp(str, "ss", 2) == 0)
			ss(a, b);
		else if (strncmp(str, "rra", 3) == 0)
			rra(a);
		else if (strncmp(str, "rrb", 3) == 0)
			rrb(b);
		else if (strncmp(str, "rrr", 3) == 0)
			rrr(a, b);
		else if (strncmp(str, "ra", 2) == 0)
			ra(a);
		else if (strncmp(str, "rb", 2) == 0)
			rb(b);
		else if (strncmp(str, "rr", 2) == 0)
			rr(a, b);
		else if (strncmp(str, "q", 1) == 0)
			return ;

		print(*a, *b);
	}
}

void	sandbox_sort(t_list **a)
{
	t_list	*b = NULL;

	instructions(a, &b);
}
