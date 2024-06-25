#include "inc/push_swap.h"

void    reverse_rotate_a(t_stack_a *stack_a)
{
    t_list *lst_first;

    lst_first = (*stack_a->list);
    while ((*stack_a->list)->next->next != NULL)
        (*stack_a->list) = (*stack_a->list)->next;
    (*stack_a->list)->next->next = lst_first;
    (*stack_a->list)->next = NULL;
    ft_printf("rra\n");
}

void    reverse_rotate_b(t_stack_b *stack_b)
{
    t_list *lst_first;

    lst_first = (*stack_b->list);
    while ((*stack_b->list)->next->next != NULL)
        (*stack_b->list) = (*stack_b->list)->next;
    (*stack_b->list)->next->next = lst_first;
    (*stack_b->list)->next = NULL;
    ft_printf("rrb\n");
}

void    reverse_rotate_ab(t_stack_a *stack_a, t_stack_b *stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
}