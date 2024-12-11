#include "../includes/push_swap.h"

static void    ft_putchar(char c)
{
    write(1, &c, 1);
}

static void    ft_putnbr(int nbr)
{
    long n;

    n = nbr;
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n <= 9)
    {
        ft_putchar(n + 48);
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

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

#include <stdio.h>
void	ft_print_actions(t_list *node)
{
	printf("\n\nValue : %d\n", node->value);
	printf("sa : %d\n", node->actions->sa);
	printf("sb : %d\n", node->actions->sb);
	printf("ss : %d\n", node->actions->ss);
	printf("pa : %d\n", node->actions->pa);
	printf("pb : %d\n", node->actions->pb);
	printf("ra : %d\n", node->actions->ra);
	printf("rb : %d\n", node->actions->rb);
	printf("rr : %d\n", node->actions->rr);
	printf("rra : %d\n", node->actions->rra);
	printf("rrb: %d\n", node->actions->rrb);
	printf("rrr: %d\n", node->actions->rrr);
}