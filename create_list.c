#include "inc/push_swap.h"

void    free_list(t_list *head)
{
    t_list  *lst;

    while (head)
    {
        lst = head;
        head = head->next;
        lst->content = NULL;
        free(lst);
    }
}

void    create_list(t_stack_a *stack_a)
{
    int     i;
    t_list  *head;
    t_list  *new_lst;

    stack_a->list = (t_list**)malloc(sizeof(t_list*));
    if (!(stack_a->list))
        ft_error_allocated(MALLOC_ERR, stack_a);
    *stack_a->list = ft_lstnew((char *)stack_a->args[0]);
    if (!(*stack_a->list))
        ft_error_allocated(MALLOC_ERR, stack_a);
    head = *stack_a->list;
    i = 1;
    while (stack_a->args[i])
    {
        new_lst = ft_lstnew((char *)stack_a->args[i]);
        if (!new_lst)
        {
            free_list(head);
            ft_error_allocated(MALLOC_ERR, stack_a);
        }
        ft_lstadd_back(stack_a->list, new_lst);
        i++;
    }
    *stack_a->list = head;
    ft_double_free(stack_a->args);
}