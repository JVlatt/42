#include "../includes/push_swap.h"

static int	get_action_cost(t_list *node)
{
	int	cost;

	cost = 0;
	cost += node->actions->sa;
	cost += node->actions->sb;
	cost += node->actions->ss;
	cost += node->actions->pa;
	cost += node->actions->pb;
	cost += node->actions->ra;
	cost += node->actions->rb;
	cost += node->actions->rr;
	cost += node->actions->rrb;
	cost += node->actions->rra;
	cost += node->actions->rrr;

	return (cost);
}

static t_list	*get_cheapest_action(t_list *stack_source)
{
	t_list	*node;
	t_list	*cheapest_node;

	node = stack_source;
	cheapest_node = stack_source;
	while(node)
	{
		if(get_action_cost(node) < get_action_cost(cheapest_node))
			cheapest_node = node;
		node = node->next;
	}
	return (cheapest_node);	
}

#include <stdio.h>
static void	execute_action(char *action_name, int count, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if(ft_strcmp(action_name,"sa") == 0)
			ft_stack_swap(stack_a);
		else if(ft_strcmp(action_name,"sb") == 0)
			ft_stack_swap(stack_b);
		else if(ft_strcmp(action_name,"ss") == 0)
		{
			ft_stack_swap(stack_b);
			ft_stack_swap(stack_a);
		}
		else if(ft_strcmp(action_name,"pa") == 0)
			ft_stack_push(stack_b, stack_a);
		else if(ft_strcmp(action_name,"pb") == 0)
			ft_stack_push(stack_a, stack_b);
		else if(ft_strcmp(action_name,"ra") == 0)
			ft_rotate(stack_a);
		else if(ft_strcmp(action_name,"rb") == 0)
			ft_rotate(stack_b);
		else if(ft_strcmp(action_name,"rr") == 0)
		{
			ft_rotate(stack_a);
			ft_rotate(stack_b);
		}
		else if(ft_strcmp(action_name,"rra") == 0)
			ft_reverse_rotate(stack_a);
		else if(ft_strcmp(action_name,"rrb") == 0)
			ft_reverse_rotate(stack_b);
		else if(ft_strcmp(action_name,"rrr") == 0)
		{
			ft_reverse_rotate(stack_a);
			ft_reverse_rotate(stack_b);
		}
		printf("%s\n", action_name); //TEMP
		i++;
	}
	
}

void	execute_node_action(t_list **source_stack, t_list **dest_stack, t_list *node)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if ((*source_stack)->stack_id == 'a')
	{
		stack_a = source_stack;
		stack_b = dest_stack;
	}
	else
	{
		stack_a = dest_stack;
		stack_b = source_stack;
	}
	execute_action("sa",node->actions->sa, stack_a, stack_b);
	execute_action("sb",node->actions->sb, stack_a, stack_b);
	execute_action("ss",node->actions->ss, stack_a, stack_b);
	execute_action("ra",node->actions->ra, stack_a, stack_b);
	execute_action("rb",node->actions->rb, stack_a, stack_b);
	execute_action("rr",node->actions->rr, stack_a, stack_b);
	execute_action("rra",node->actions->rra, stack_a, stack_b);
	execute_action("rrb",node->actions->rrb, stack_a, stack_b);
	execute_action("rrr",node->actions->rrr, stack_a, stack_b);
	execute_action("pa",node->actions->pa, stack_a, stack_b);
	execute_action("pb",node->actions->pb, stack_a, stack_b);
	//ft_print_stacks(stack_a, stack_b);
}
void	execute_cheapest_action(t_list **source_stack, t_list **dest_stack)
{
	t_list	*cheapest_action;
	cheapest_action = get_cheapest_action(*source_stack);
	//printf("Cheapest Action on value %d cost %d\n", cheapest_action->value, get_action_cost(cheapest_action)); //TEMP
	execute_node_action(source_stack, dest_stack, cheapest_action);
}
