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

void    ft_error_allocated(char *str, t_stack *stack)
{
    t_list  *lst;

    if (stack->args)
        ft_double_free(stack->args);
    if (stack->stack_a)
    {
        while (*stack->stack_a)
        {
            lst = *stack->stack_a;
            *stack->stack_a = (*stack->stack_a)->next;
            lst->content = 0;
            free(lst);
        }
        free(*stack->stack_a);
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