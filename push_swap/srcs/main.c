#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;

    if(argc >= 3)
    {
        argv++;
        stack_a = parse_args(argc - 1, argv);
        stack_b = NULL;
        ft_print_stacks(stack_a, stack_b);
		ft_stack_push(&stack_a, &stack_b);
		ft_stack_push(&stack_a, &stack_b);
        ft_print_stacks(stack_a, stack_b);
		
		// ft_stack_swap(&stack_a);     
        // ft_print_stacks(stack_a, stack_b);  
		// ft_stack_push(&stack_a, &stack_b);    
		// ft_stack_push(&stack_a, &stack_b);    
		// ft_stack_push(&stack_a, &stack_b);    
        // ft_print_stacks(stack_a, stack_b);  
		// ft_rotate(&stack_a);
		// ft_rotate(&stack_b);
        // ft_print_stacks(stack_a, stack_b);  
		// ft_reverse_rotate(&stack_a);
		// ft_reverse_rotate(&stack_b);
        // ft_print_stacks(stack_a, stack_b);  
		// ft_stack_push(&stack_a, &stack_b);    
		// ft_stack_push(&stack_a, &stack_b);    
		// ft_stack_push(&stack_a, &stack_b);    
        // ft_print_stacks(stack_a, stack_b);
		ft_lstclear(&stack_a);  
		ft_lstclear(&stack_b);  
    }
}