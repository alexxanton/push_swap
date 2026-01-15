#include <time.h>
#include "../include/push_swap.h"
#define RANGE 2001

int	*num_gen(char *str)
{
	int	len;
	int	*arr;
	int	num;
	int	pool[RANGE];

	srand(time(NULL));
	len = atoi(str);
	arr = malloc(sizeof(int) * len);
	num = -(RANGE - 1) / 2;

	for (int i = 0; i < RANGE; i++)
	{
		pool[i] = num++;
	}

	//for (int i = 0; i < RANGE; i++)
	//	printf("%d ", pool[i]);
	//printf("\n");
	//return NULL;

	for (int i = 0; i < len; i++)
	{
		int	index = rand() % (RANGE - i);

		arr[i] = pool[index];
		pool[index] = pool[RANGE - i - 1];
	}

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return arr;
}

int	main(void)
{
	char	str[10];
	int		*arr;

	read(1, str, 10);
	arr = num_gen(str);
	free(arr);
	//num_gen("1000");
}
