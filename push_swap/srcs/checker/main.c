/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:38:14 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/27 15:27:20 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker/checker.h"

static void	execute_action(char *action_name,
			t_list **stack_a, t_list **stack_b)
{
	if (action_name[0] == 's')
		execute_swap(action_name[1], stack_a, stack_b);
	else if (action_name[0] == 'p')
		execute_push(action_name[1], stack_a, stack_b);
	else if (action_name[0] == 'r' && ft_strlen(action_name) == 3)
		execute_rotate(action_name[1], stack_a, stack_b);
	else if (action_name[0] == 'r' && ft_strlen(action_name) == 4)
		execute_reverse_rotate(action_name[2], stack_a, stack_b);
}

static int	check_result(t_list *stack_a, t_list *stack_b)
{
	t_list	*node;

	if (stack_b)
		return (0);
	node = stack_a;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	read_inputs(t_list **stack_a, t_list **stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		execute_action(input, stack_a, stack_b);
		input = get_next_line(0);
	}
	if (check_result(*stack_a, *stack_b))
		ft_printf("OK");
	else
		ft_printf("K0");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
			stack_a = parse_string(argv[1]);
		else
		{
			argv++;
			stack_a = parse_args(argc - 1, argv);
		}
		if (!stack_a)
			return (1);
		read_inputs(&stack_a, &stack_b);
	}
}
