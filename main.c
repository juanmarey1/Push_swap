#include "inc/push_swap.h"

void    struct_init(t_stack *stack)
{
    stack->args = NULL;
    stack->stack_a = NULL;
    stack->stack_b = NULL;
    stack->atoi_error = 0;
    stack->moves = 0;
    stack->a_nums = 0;
    stack->b_nums = 0;
}

void    args_control(int argc, char **argv, t_stack *stack)
{
    if (argc < 2 || argc > 501)
        ft_error(ARGS_ERROR);
    if (argc == 2)
        check_args_int_1(argv, stack);
    else
        check_args_int_2(argc, argv, stack);
    check_args_max_int(stack);
}

void    algorithm(t_stack  *stack)
{
    stack->stack_b = (t_list**)malloc(sizeof(t_list*));
    *stack->stack_b = NULL;
    push_b(stack);
    push_b(stack);
    stack->a_nums = stack->a_nums - 2;
    stack->b_nums = stack->b_nums + 2;
    while (stack->a_nums > 3)
    {
        stack->num_list_a = find_cost(stack);
        push_a_to_b(stack);
        stack->a_nums--;
        stack->b_nums++;
    }
    sort_3_nums(stack);
    while (stack->b_nums > 0)
    {
        back_to_a(stack);
        stack->b_nums--;
        stack->a_nums++;
    }
    t_list *list_a;
    t_list *list_b;
    numbers_ordered(stack);
        list_a = *stack->stack_a;
    list_b = *stack->stack_b;
    printf("//////////////LIST     A/////////////////////\n");
    while (list_a != NULL)
    {
        printf("%d\n", list_a->content);
        list_a = list_a->next;
    }
    printf("//////////////LIST     B/////////////////////\n");
    while (list_b != NULL)
    {
        printf("%d\n", list_b->content);
        list_b = list_b->next;
    }
}

int main(int argc, char *argv[])
{
    t_stack stack;

    struct_init(&stack);
    args_control(argc, argv, &stack);
    create_list(&stack);
    // if (stack.a_nums == 4)
    if (stack.a_nums > 3 && stack.a_nums != 4)
        algorithm(&stack);
    else if (stack.a_nums == 2)
    {
        if ((*stack.stack_a)->content > (*stack.stack_a)->next->content)
            swap_a(&stack);
    }
    else
        sort_3_nums(&stack);
    // else condition for 3 or less
}