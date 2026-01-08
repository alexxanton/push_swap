#include <../include/push_swap.h>

char	*sa(t_list *a)
{
	t_list	*stack;
	t_list	*next;
	int		swap;

	if (!a)
		return ("");
	stack = a;
	swap = stack->num;
	if (!stack->next)
		return ("");
	next = stack->next;
	swap = stack->num;
	stack->num = next->num;
	next->num = swap;
	return ("sa");
}

char	*sb(t_list *b)
{
	if (sa(b))
		return ("sb");
	return ("");
}

char	*ss(t_list *a, t_list *b)
{
	if (sa(a) && sa(b))
		return ("ss");
	return ("");
}
