#include "../include/push_swap.h"
#include <string.h>

void	print(t_list *list)
{
	printf("- -\n");
	while (list)
	{
		printf("%d\n", list->num);
		list = list->next;
	}
}

void	instructions(t_list **a, t_list **b)
{
	char	str[4];

	print(*a);
	while (!is_sorted(*a))
	{
		read(1, str, 4);
		if (strncmp(str, "sa", 2) == 0)
			sa(a);
		else if (strncmp(str, "sb", 2) == 0)
			sb(b);
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

		print(*a);
	}
}

void	sandbox_sort(t_list **a)
{
	t_list	*b;

	instructions(a, &b);
}

void	sandbox(t_list *stack)
{
	(void)stack;
}
