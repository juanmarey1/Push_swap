#include "inc/push_swap.h"

void    swap_a(t_stack *stack)
{
    t_list  *lst;
    void    *aux;
    
    lst = *stack->stack_a;
    aux = lst->content;
    lst->content = lst->next->content;
    lst->next->content = aux;
    ft_printf("sa\n");
}

void    swap_b(t_stack *stack)
{
    t_list  *lst;
    void    *aux;
    
    lst = *stack->stack_b;
    aux = lst->content;
    lst->content = lst->next->content;
    lst->next->content = aux;
    ft_printf("sb\n");
}

void    swap_ab(t_stack *stack)
{
    t_list  *lst;
    t_list  *lst2;
    void    *aux;
    
    lst = (*stack->stack_a);
    aux = lst->content;
    lst->content = lst->next->content;
    lst->next->content = aux;
    lst2 = (*stack->stack_b);
    aux = lst2->content;
    lst2->content = lst2->next->content;
    lst2->next->content = aux;
    ft_printf("ss\n");
}