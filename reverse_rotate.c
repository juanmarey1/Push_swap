#include "inc/push_swap.h"

void    reverse_rotate_a(t_stack *stack)
{
    t_list *lst_first;

    lst_first = (*stack->stack_a);
    while (lst_first->next->next != NULL)
        lst_first = (lst_first)->next;
    ft_lstadd_front(stack->stack_a, lst_first->next);
    lst_first->next = NULL;
    ft_printf("rra\n");
    stack->movements++;
}

void    reverse_rotate_b(t_stack *stack)
{
    t_list *lst_first;

    lst_first = (*stack->stack_b);
    while (lst_first->next->next != NULL)
        lst_first = lst_first->next;
    ft_lstadd_front(stack->stack_b, lst_first->next);
    lst_first->next = NULL;
    ft_printf("rrb\n");
    stack->movements++;
}

void    reverse_rotate_ab(t_stack *stack)
{
    t_list *lst_first;
    t_list *lst_first2;

    lst_first = (*stack->stack_a);
    while (lst_first->next->next != NULL)
        lst_first = (lst_first)->next;
    ft_lstadd_front(stack->stack_a, lst_first->next);
    lst_first->next = NULL;
    lst_first2 = (*stack->stack_b);
    while (lst_first2->next->next != NULL)
        lst_first2 = lst_first2->next;
    ft_lstadd_front(stack->stack_b, lst_first2->next);
    lst_first2->next = NULL;
    ft_printf("rrr\n");
    stack->movements++;
}