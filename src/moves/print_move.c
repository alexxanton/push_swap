#include <../include/push_swap.h>

void	print_move(char *move)
{
	write(1, move, ft_strlen(move));
	write(1, "\n", 1);
}
