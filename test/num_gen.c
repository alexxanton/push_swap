#include <time.h>
#include "../include/push_swap.h"
#define RANGE 2001

t_list	*num_gen(char *str)
{
	int		len;
	int		num;
	int		pool[RANGE];
	t_list	*arr;
	t_list	*next;

	srand(time(NULL));
	len = atoi(str);
	arr = malloc(sizeof(t_list));
	num = -(RANGE - 1) / 2;

	for (int i = 0; i < RANGE; i++)
	{
		pool[i] = num++;
	}

	//for (int i = 0; i < RANGE; i++)
	//	printf("%d ", pool[i]);
	//printf("\n");
	//return NULL;

	next = arr;
	for (int i = 0; i < len; i++)
	{
		int	index = rand() % (RANGE - i);

		next->next = NULL;
		next->num = pool[index];
		pool[index] = pool[RANGE - i - 1];
		if (i < len - 1)
		{
			next->next = malloc(sizeof(t_list));
			next = next->next;
		}
	}

	//for (int i = 0; i < len; i++)
	//	printf("%d ", arr[i]);
	//printf("\n");

	return arr;
}

int	main(void)
{
	char	str[10];
	t_list	*arr;

	read(1, str, 10);
	arr = num_gen(str);
	sort(&arr);
	free(arr);
	//num_gen("1000");
}
