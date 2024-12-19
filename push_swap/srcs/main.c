/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:38:14 by mmanuell          #+#    #+#             */
/*   Updated: 2024/12/19 16:45:59 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else if (ft_lstsize(stack_a) > 3)
			sort_stacks(&stack_a, &stack_b);
		ft_lstclear(&stack_a, &delete_node_content);
	}
}
