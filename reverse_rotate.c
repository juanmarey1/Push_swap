#include "inc/push_swap.h"

void    reverse_rotate_a(t_stack_a *stack_a)
{
    t_list *lst_first;

    lst_first = (*stack_a->list);
    while (lst_first->next->next != NULL)
        lst_first = (lst_first)->next;
    ft_lstadd_front(stack_a->list, lst_first->next);
    lst_first->next = NULL;
    ft_printf("rra\n");
}

void    reverse_rotate_b(t_stack_b *stack_b)
{
    t_list *lst_first;

    lst_first = (*stack_b->list);
    while (lst_first->next->next != NULL)
        lst_first = lst_first->next;
    ft_lstadd_front(stack_b->list, lst_first->next);
    lst_first->next = NULL;
    ft_printf("rrb\n");
}

void    reverse_rotate_ab(t_stack_a *stack_a, t_stack_b *stack_b)
{
    t_list *lst_first;
    t_list *lst_first2;

    lst_first = (*stack_a->list);
    while (lst_first->next->next != NULL)
        lst_first = (lst_first)->next;
    ft_lstadd_front(stack_a->list, lst_first->next);
    lst_first->next = NULL;
    lst_first2 = (*stack_b->list);
    while (lst_first2->next->next != NULL)
        lst_first2 = lst_first2->next;
    ft_lstadd_front(stack_b->list, lst_first2->next);
    lst_first2->next = NULL;
    printf("rrr\n");
}