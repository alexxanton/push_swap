void	s3(t_list *stack)
{
	if (nums[0] > nums[1] && nums[1] < nums[2])
		ra(&stack);
	else if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		ra(&stack);
		sa(&stack);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] < nums[2])
	{
		sa(&stack);
		ra(&stack);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] > nums[2])
	{
		rra(&stack);
	}
	return (1);
}

int	sort_three_nums(t_list *stack)
{
	int		nums[3];
	int		i;

	i = 0;
	while (i < 3)
	{
		nums[i] = stack->num;
		if (stack->next)
			stack = stack->next;
		i++;
	}
}
