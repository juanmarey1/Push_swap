#include "inc/push_swap.h"

int find_closest_number_to_a(int num_a, t_list *list_b)
{
    int min_diff;
    int num_diff;
    int diff;

    while (num_a < (list_b->content))
        list_b = list_b->next;
    num_diff = (list_b->content);
    min_diff = num_a - (list_b->content);
    while (list_b != NULL)
    {
        if (num_a > (list_b->content))
        {
            diff = num_a - list_b->content;
            if (diff < min_diff)
            {
                num_diff = (list_b->content);
                min_diff = diff;
            }
        }
        list_b = list_b->next;
    }
    return (num_diff);
}

int find_opt_moves_a(t_stack *stack, int i)
{
    int a_nums;

    a_nums = stack->a_nums;
    stack->up_a = 0;
    stack->down_a = 0;
    if (a_nums % 2 == 0)
    {
        if (i <= (a_nums / 2))
            return (stack->up_a = i - 1, stack->down_a = (a_nums - i) + 1, i);
        else
            return (stack->down_a = (a_nums - i) + 1, 
                stack->up_a = i - 1, (a_nums - i) + 2);
    }
    else
    {
        if (i <= (a_nums + 1) / 2)
            return (stack->up_a = i - 1, stack->down_a = (a_nums - i) + 1, i);
        else
            return (stack->down_a = (a_nums - i) + 1, 
                stack->up_a = i - 1, (a_nums - i) + 2);
    }
}

int    find_common_actions(t_stack *stack, int num)
{
    if (num == 1)
    {
        if (stack->up_a == stack->up_b)
            return (stack->common_up = stack->up_a, stack->up_a);
        else if (stack->up_a < stack->up_b)
            return (stack->common_up = stack->up_a, stack->up_b);
        else
            return (stack->common_up = stack->up_b, stack->up_a);
    }
    else
    {
        if (stack->down_a == stack->down_b)
            return (stack->common_down = stack->down_a, stack->down_a);
        else if (stack->down_a < stack->down_b)
            return (stack->common_down = stack->down_a, stack->down_b);
        else
            return (stack->common_down = stack->down_b, stack->down_a);
    }
}

int find_opt_moves(t_stack *stack)
{
    if ((stack->up_ab <= stack->down_ab && stack->up_ab <= stack->up_a_down_b)
            && stack->up_ab <= stack->down_a_up_b)
    {
        return (stack->which_case = 1, stack->up_ab);
    }
    else if ((stack->down_ab <= stack->up_ab && stack->down_ab <= stack->up_a_down_b)
            && stack->down_ab <= stack->down_a_up_b)
    {
        return (stack->which_case = 2, stack->down_ab);
    }
    else if ((stack->up_a_down_b <= stack->up_ab && stack->up_a_down_b <= stack->down_ab
            && stack->up_a_down_b <= stack->down_a_up_b))
    {
        return (stack->which_case = 3, stack->up_a_down_b);
    }
    else
    {
        return (stack->which_case = 4, stack->down_a_up_b);
    }
}

int find_opt_moves_b(t_stack *stack, int j)
{
    int b_nums;

    b_nums = stack->b_nums;
    stack->common_up = 0;
    stack->common_down = 0;
    stack->num_list_b = j;
    stack->up_b = j - 1;
    stack->down_b = b_nums - j + 1;
    stack->up_a_down_b = stack->up_a + stack->down_b;
    stack->down_a_up_b = stack->down_a + stack->up_b;
    stack->up_ab = find_common_actions(stack, 1);
    stack->down_ab = find_common_actions(stack, -1);
    j = find_opt_moves(stack);
    return (j);
}
