#include <../include/push_swap.h>

void	sa(t_list *a)
{
	t_list	*stack;
	t_list	*next;
	int		swap;

	stack = a;
	swap = stack->num;
	if (stack->next)
		next = stack->next;
	swap = stack->num;
	stack->num = next->num;
	next->num = swap;
}

void	sb(t_list *a, t_list *b)
{
	sa(a);
	(void)b;
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	(void)b;
}
