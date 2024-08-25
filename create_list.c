#include "inc/push_swap.h"

void    free_list(t_list *head)
{
    t_list  *lst;

    while (head)
    {
        lst = head;
        head = head->next;
        lst->content = 0;
        free(lst);
    }
}

void    create_list(t_stack *stack)
{
    int     i;
    t_list  *head;
    t_list  *new_lst;

    stack->stack_a = (t_list**)malloc(sizeof(t_list*));
    if (!(stack->stack_a))
        ft_error(MALLOC_ERR, stack);
    *stack->stack_a = ft_lstnew(ft_atoi((char *)stack->args[0]));
    if (!(*stack->stack_a))
        ft_error(MALLOC_ERR, stack);
    head = *stack->stack_a;
    i = 1;
    while (stack->args[i])
    {
        new_lst = ft_lstnew(ft_atoi((char *)stack->args[i]));
        if (!new_lst)
        {
            free_list(head);
            ft_error(MALLOC_ERR, stack);
        }
        ft_lstadd_back(stack->stack_a, new_lst);
        i++;
    }
    stack->a_nums = i;
    *stack->stack_a = head;
    ft_double_free(stack->args, stack);
}