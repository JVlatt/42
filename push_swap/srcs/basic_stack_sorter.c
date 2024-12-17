#include "../includes/push_swap.h"

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || ft_lstsize(*stack) != 3)
		return ;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && third < first) // Case [3, 1, 2]
		execute_rotate('a', stack, NULL);
	else if (first < second && second > third && third < first) // Case [2, 3, 1]
		execute_reverse_rotate('a', stack, NULL);
	else if (first > second && second < third && third > first) // Case [2, 1, 3]
		execute_swap('a', stack, NULL);
	else if (first < second && second > third && third > first) // Case [1, 3, 2]
	{
		execute_swap('a', stack, NULL); // [3, 1, 2]
		execute_rotate('a', stack, NULL);
	}
	else if (first > second && second > third) // Case [3, 2, 1]
	{
		execute_swap('a', stack, NULL); // [2, 3, 1]
		execute_reverse_rotate('a', stack, NULL);
	}
}