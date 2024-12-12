#include "../includes/push_swap.h"

static int ft_isnum(char *str)
{
    while(*str)
    {
        if(!(*str >= '0' && *str <= '9') && *str != '-')
            return (0);
        str++;
    }
    return (1);
}

static int is_valid_arg(t_list *head, char *arg)
{
    t_list  *node;
    if (!ft_isnum(arg))
        return (0);
    node = head;
    while (node)
    {
        if(node->value == ft_atoi(arg))
            return (0);
        node = node->next;
    }
    return (1);
}

t_list  *parse_args(int argc, char **args)
{
    t_list  *arg_list;
    int     i;

    i = 0;
    while (i < argc)
    {
        if (is_valid_arg(arg_list, args[i]))
        {
            if(!arg_list)
                arg_list = ft_lstnew(ft_atoi(args[i]), 'a');
            else
                ft_lstadd_back(&arg_list, ft_lstnew(ft_atoi(args[i]), 'a'));
        }
        else
        {
            ft_lstclear(&arg_list, &delete_node_content);
            write(1,"Error\n",6);
            return (NULL);
        }
        i++;
    }
    return (arg_list);
}