#include "inc/push_swap.h"

void    push_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
    t_list *new;
    t_list *lsta;

    lsta = (*stack_b->list)->next;
    new = ft_lstnew((*stack_b->list)->content);
    ft_lstadd_front(stack_a->list, new);
    (*stack_b->list)->content = NULL;
    (*stack_b->list)->next = NULL;
    free(*stack_b->list);
    *stack_b->list = lsta;
    ft_printf("pb\n");
}

void    push_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
    t_list *new;
    t_list *lsta;

    lsta = (*stack_a->list)->next;
    new = ft_lstnew((*stack_a->list)->content);
    ft_lstadd_front(stack_b->list, new);
    (*stack_a->list)->content = NULL;
    (*stack_a->list)->next = NULL;
    free(*stack_a->list);
    *stack_a->list = lsta;
    ft_printf("pb\n");
}