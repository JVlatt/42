#include "../includes/push_swap.h"


void    ft_print_stacks(t_list **stack_a, t_list **stack_b)
{
    t_list  *node_to_print_a;
    t_list  *node_to_print_b;

    node_to_print_b = *stack_b;
    node_to_print_a = *stack_a;
    while (node_to_print_a || node_to_print_b)
    {
		if(node_to_print_a)
		{
        	ft_putnbr(node_to_print_a->value);
	        node_to_print_a = node_to_print_a->next;
		}
		else
			ft_putchar(' ');
        ft_putchar('\t');
		if(node_to_print_b)
		{
        	ft_putnbr(node_to_print_b->value);
	        node_to_print_b = node_to_print_b->next;
		}
		else
			ft_putchar(' ');
		ft_putchar('\n');
    }
	write(1, "_\t_\n", 4);
	write(1, "A\tB\n\n", 5);
}

// void	ft_print_actions(t_list *node)
// {
// 	ft_printf("\n\nValue : %d\n", node->value);
// 	ft_printf("sa : %d\n", node->actions->sa);
// 	ft_printf("sb : %d\n", node->actions->sb);
// 	ft_printf("ss : %d\n", node->actions->ss);
// 	ft_printf("pa : %d\n", node->actions->pa);
// 	ft_printf("pb : %d\n", node->actions->pb);
// 	ft_printf("ra : %d\n", node->actions->ra);
// 	ft_printf("rb : %d\n", node->actions->rb);
// 	ft_printf("rr : %d\n", node->actions->rr);
// 	ft_printf("rra : %d\n", node->actions->rra);
// 	ft_printf("rrb: %d\n", node->actions->rrb);
// 	ft_printf("rrr: %d\n", node->actions->rrr);
// }