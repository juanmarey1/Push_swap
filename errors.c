#include "inc/push_swap.h"

void    ft_double_free(char **double_str)
{
    int i;

    i = 0;
    while (double_str[i])
    {
        free(double_str[i]);
        i++;
    }
    free(double_str);
    double_str = NULL;
}

void    ft_error_allocated(char *str, t_stack_a *stack_a)
{
    t_list  *lst;

    if (stack_a->args)
        ft_double_free(stack_a->args);
    if (stack_a->list)
    {
        while (*stack_a->list)
        {
            lst = *stack_a->list;
            *stack_a->list = (*stack_a->list)->next;
            lst->content = NULL;
            free(lst);
        }
        free(stack_a->list);
    }
    ft_error(str);
}

void    ft_error(char *str)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd("\n", 2);
    exit (1);
}