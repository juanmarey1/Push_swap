#include "inc/push_swap.h"

int find_closest_num_to_a(int num_a, t_list *list_b, int num_diff, int min_diff)
{
    int diff;

    while (list_b != NULL)
    {
        if (num_a > ft_atoi(list_b->content))
        {
            diff = num_a - ft_atoi(list_b->content);
            if (diff < min_diff)
            {
                num_diff = ft_atoi(list_b->content);
                min_diff = diff;
            }
        }
        if (list_b->next = NULL)
            break ;
        list_b = list_b->next;
    }
    return (num_diff);
}

int find_closest_number_to_a(int num_a, t_list *list_b)
{
    int diff;
    int min_diff;
    int num_diff;

    while (list_b->next != NULL)
    {
        if (num_a > ft_atoi(list_b->content))
        {
            num_diff = ft_atoi(list_b->content);
            min_diff = num_a - ft_atoi(list_b->content);
        }
        list_b = list_b->next;
    }
    num_diff = find_closest_num_to_a(num_a, list_b, num_diff, min_diff);
    return (num_diff);
}

int find_opt_moves_a(t_stack *stack, int i)
{
    int a_nums;

    a_nums = stack->a_nums;
    if (a_nums % 2 == 0)
    {
        if (i <= (a_nums / 2))
            return (i);
        else
            return ((a_nums - i) + 2);
    }
    else
    {
        if (i <= ((a_nums / 2) + 1))
            return (i);
        else
            return ((a_nums - i) + 2);
    }
}

int find_opt_moves_b(t_stack *stack, int i)
{
    int b_nums;

    b_nums = stack->b_nums;
    if (b_nums % 2 == 0)
    {
        if (i <= (b_nums / 2))
            return (i);
        else
            return ((b_nums - i) + 2);
    }
    else
    {
        if (i <= ((b_nums / 2) + 1))
            return (i);
        else
            return ((b_nums - i) + 2);
    }
}