#include "inc/push_swap.h"

void    rotate_a(t_stack_a *stack_a)
{
    t_list  *lst_first;
    
    lst_first = *stack_a->list;
    while ((*stack_a->list)->next != NULL)
        (*stack_a->list) = (*stack_a->list)->next;
    (*stack_a->list)->next = lst_first;
    (*stack_a->list) = (*stack_a->list)->next->next;
    lst_first->next = NULL;
    ft_printf("ra\n");
}

void    rotate_b(t_stack_b *stack_b)
{
    t_list  *lst_first;
    
    lst_first = *stack_b->list;
    while ((*stack_b->list)->next != NULL)
        (*stack_b->list) = (*stack_b->list)->next;
    (*stack_b->list)->next = lst_first;
    (*stack_b->list) = (*stack_b->list)->next->next;
    lst_first->next = NULL;
    ft_printf("rb\n");
}

void    rotate_ab(t_stack_a *stack_a, t_stack_b *stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}