#include "inc/push_swap.h"

void    sort_4_nums(t_stack *stack)
{
    stack->stack_b = (t_list**)malloc(sizeof(t_list*));
    if (!stack->stack_b)
        return ;
    push_b(stack);
    stack->b_nums++;
    stack->a_nums--;
    sort_3_nums(stack);
    back_to_a(stack);
    stack->b_nums--;
    stack->a_nums++;
    numbers_ordered(stack);
    *stack->stack_b = NULL;
}