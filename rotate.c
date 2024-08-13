#include "inc/push_swap.h"

void    rotate_a(t_stack *stack)
{
    t_list  *lst_first;
    
    lst_first = *stack->stack_a;
    while ((*stack->stack_a)->next != NULL)
        (*stack->stack_a) = (*stack->stack_a)->next;
    (*stack->stack_a)->next = lst_first;
    (*stack->stack_a) = (*stack->stack_a)->next->next;
    lst_first->next = NULL;
    ft_printf("ra\n");
}

void    rotate_b(t_stack *stack)
{
    t_list  *lst_first;
    
    lst_first = *stack->stack_b;
    while ((*stack->stack_b)->next != NULL)
        (*stack->stack_b) = (*stack->stack_b)->next;
    (*stack->stack_b)->next = lst_first;
    (*stack->stack_b) = (*stack->stack_b)->next->next;
    lst_first->next = NULL;
    ft_printf("rb\n");
}

void    rotate_ab(t_stack *stack)
{
    t_list  *lst_first;
    t_list  *lst_first2;
    
    lst_first = *stack->stack_a;
    while ((*stack->stack_a)->next != NULL)
        (*stack->stack_a) = (*stack->stack_a)->next;
    (*stack->stack_a)->next = lst_first;
    (*stack->stack_a) = (*stack->stack_a)->next->next;
    lst_first->next = NULL;
    lst_first2 = *stack->stack_b;
    while ((*stack->stack_b)->next != NULL)
        (*stack->stack_b) = (*stack->stack_b)->next;
    (*stack->stack_b)->next = lst_first2;
    (*stack->stack_b) = (*stack->stack_b)->next->next;
    lst_first2->next = NULL;
    ft_printf("rr\n");
}