#include "inc/push_swap.h"

void    create_list(int argc, char **argv, t_stack_a *stack_a)
{
    int i;
    t_list  *head;

    i = 0;
    stack_a->list = (t_list **)malloc(sizeof(t_list*) * argc);
    while (stack_a->args[i])
    {
        head = ft_lstnew(ft_atoi(stack_a->args[i]));
        ft_lstadd_back(stack_a->list, head);
        i++;
    }
}