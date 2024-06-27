#include "inc/push_swap.h"

void    struct_init(t_stack_a *stack_a, t_stack_b *stack_b)
{
    stack_a->args = NULL;
    stack_a->list = NULL;
    stack_b->list = NULL;
}

void    args_control(int argc, char **argv, t_stack_a *stack_a)
{
    if (argc < 2 || argc > 501)
        ft_error(ARGS_ERROR);
    if (argc == 2)
        check_args_int_1(argv, stack_a);
    else
        check_args_int_2(argc, argv, stack_a);
    check_args_max_int(stack_a);
}

int main(int argc, char *argv[])
{
    t_stack_a stack_a;
    t_stack_b   stack_b;

    struct_init(&stack_a, &stack_b);
    args_control(argc, argv, &stack_a);
    create_list(&stack_a);
}