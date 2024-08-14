#include "inc/push_swap.h"

void    push_a(t_stack *stack)
{
    t_list *new;
    t_list *lsta;

    lsta = (*stack->stack_b)->next;
    new = ft_lstnew((*stack->stack_b)->content);
    ft_lstadd_front(stack->stack_a, new);
    (*stack->stack_b)->content = 0;
    (*stack->stack_b)->next = NULL;
    free(*stack->stack_b);
    *stack->stack_b = lsta;
    ft_printf("pa\n");
}

void    push_b(t_stack *stack)
{
    t_list *new;
    t_list *lsta;

    lsta = (*stack->stack_a)->next;
    new = ft_lstnew((*stack->stack_a)->content);
    ft_lstadd_front(stack->stack_b, new);
    (*stack->stack_a)->content = 0;
    (*stack->stack_a)->next = NULL;
    free(*stack->stack_a);
    *stack->stack_a = lsta;
    ft_printf("pb\n");
}