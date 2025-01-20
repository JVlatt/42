/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:38:14 by mmanuell          #+#    #+#             */
/*   Updated: 2025/01/20 17:56:38 by mmanuell         ###   ########.fr       */
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
	else
	{
		ft_lstclear(stack_a, &delete_node_content);
		ft_lstclear(stack_b, &delete_node_content);
		free(action_name);
		ft_printf("Operations Error\n");
		exit(EXIT_FAILURE);
	}
}

static void	read_inputs(t_list **stack_a, t_list **stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		execute_action(input, stack_a, stack_b);
		free(input);
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
		if (is_sorted(stack_a))
		{
			ft_lstclear(&stack_a, &delete_node_content);
			return (1);
		}
		read_inputs(&stack_a, &stack_b);
		ft_lstclear(&stack_a, &delete_node_content);
	}
}
