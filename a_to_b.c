#include "inc/push_swap.h"

void    up_ab(t_stack *stack)
{
    if (stack->up_a > stack->up_b)
    {
        stack->up_a = stack->up_a - stack->up_b;
        stack->up_b = 0;
    }
    else if (stack->up_a < stack->up_b)
    {
        stack->up_b = stack->up_b - stack->up_a;
        stack->up_a = 0;
    }
    else
    {
        stack->up_a = 0;
        stack->up_b = 0;
    }
    while (stack->common_up-- > 0)
        rotate_ab(stack);
    while (stack->up_a-- > 0)
        rotate_a(stack);
    while (stack->up_b-- > 0)
        rotate_b(stack);
}

void    down_ab(t_stack *stack)
{
    if (stack->down_a > stack->down_b)
    {
        stack->down_a = stack->down_a - stack->down_b;
        stack->down_b = 0;
    }
    else if (stack->down_a < stack->down_b)
    {
        stack->down_b = stack->down_b - stack->down_a;
        stack->down_a = 0;
    }
    else
    {
        stack->down_a = 0;
        stack->down_b = 0;
    }
    while (stack->common_down-- > 0)
        reverse_rotate_ab(stack);
    while (stack->down_a-- > 0)
        reverse_rotate_a(stack);
    while (stack->down_b-- > 0)
        reverse_rotate_b(stack);
}

void    up_a_down_b(t_stack *stack)
{
    while (stack->up_a-- > 0)
        rotate_a(stack);
    while (stack->down_b-- > 0)
        reverse_rotate_b(stack);
}

void    down_a_up_b(t_stack *stack)
{
    while (stack->down_a-- > 0)
        reverse_rotate_a(stack);
    while (stack->up_b-- > 0)
        rotate_b(stack);
}

void    push_a_to_b(t_stack *stack)
{
    if (stack->which_case == 1)
        up_ab(stack);
    else if (stack->which_case == 2)
        down_ab(stack);
    else if (stack->which_case == 3)
        up_a_down_b(stack);
    else
        down_a_up_b(stack);
    push_b(stack);
}