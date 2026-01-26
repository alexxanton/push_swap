#include "test.h"

int	stack_len;

t_list	*num_gen(int range)
{
	int		pool_len = range;
	int		num = 0;

	int		*pool;
	t_list	*arr;
	t_list	*next;

	stack_len = range > 0 ? range : -range * 2;
	(void)stack_len;
	srand(time(NULL));
	arr = malloc(sizeof(t_list));
	if (range < 0)
	{
		num = range;
		range = -range;
		pool_len = range;
		pool_len = pool_len * 2 + 1;
	}
	pool = malloc(sizeof(int) * pool_len);

	for (int i = 0; i < pool_len; i++)
		pool[i] = num++;

	next = arr;
	for (int i = 0; i < range; i++)
	{
		int	index = rand() % (pool_len - i);

		next->next = NULL;
		next->num = pool[index];
		pool[index] = pool[pool_len - i - 1];
		if (i < range - 1)
		{
			next->next = malloc(sizeof(t_list));
			next = next->next;
		}
	}

	//for (int i = 0; i < range; i++)
	//	printf("%d ", arr[i]);
	//printf("\n");

	free(pool);
	return arr;
}

int	main(void)
{
	char	str[10] = "";
	char	choice[2] = "";
	char	*msg = "Enter range: ";
	char	*mode_msg = "Command mode? (y/N): ";
	t_list	*arr;

	write(1, msg, strlen(msg));
	read(1, str, 10);
	write(1, mode_msg, strlen(mode_msg));
	read(1, choice, 2);
	choice[1] = 0;

	if (strcmp(str, "\n") == 0)
		arr = num_gen(atoi("10"));
	else
		arr = num_gen(atoi(str));

	if (strcmp(choice, "y") == 0)
		sandbox_sort(&arr);
	else
		printf("%d\n", sort(&arr));
	list_clear(arr);
}
