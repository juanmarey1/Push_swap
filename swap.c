#include "inc/push_swap.h"

void    swap_a(t_stack_a *stack_a)
{
    t_list  *lst;
    void    *aux;
    
    lst = *stack_a->list;
    aux = lst->content;
    lst->content = lst->next->content;
    lst->next->content = aux;
    ft_printf("sa\n");
}

void    swap_b(t_stack_b *stack_b)
{
    t_list  *lst;
    void    *aux;
    
    lst = *stack_b->list;
    aux = lst->content;
    lst->content = lst->next->content;
    lst->next->content = aux;
    ft_printf("sb\n");
}

void    swap_ab(t_stack_a *stack_a, t_stack_b *stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
}