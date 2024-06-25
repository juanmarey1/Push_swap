#include "inc/push_swap.h"

void    push_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
    t_list *new;
    t_list *lstb;

    lstb = *stack_b->list;
    *stack_b->list++;
    new = ft_lstnew(lstb->content);
    ft_lstadd_front(stack_a->list, new);
    lstb->content = NULL;
    lstb->next = NULL;
    free(lstb);
    ft_printf("pa\n");
}

void    push_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
    t_list *new;
    t_list *lsta;

    lsta = *stack_a->list;
    *stack_a->list++;
    new = ft_lstnew(lsta->content);
    ft_lstadd_front(stack_b->list, new);
    lsta->content = NULL;
    lsta->next = NULL;
    free(lsta);
    ft_printf("pb\n");
}