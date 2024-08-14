#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "messages.h"

typedef struct s_stack
{
    char    **args;
    t_list  **stack_a;
    int     a_nums;
    t_list  **stack_b;
    int     b_nums;
    int     atoi_error;
    int     moves;
    int     num_list_a;
    int     num_list_b;
    int     up_a;
    int     up_b;
    int     down_a;
    int     down_b;
    int     up_ab;
    int     down_ab;
    int     up_a_down_b;
    int     down_a_up_b;
    int     common_up;
    int     common_down;
    int     which_case;
}   t_stack;

void    ft_double_free(char **double_str);
void    ft_error(char *str);
void    ft_error_allocated(char *str, t_stack *stack);

void    check_args_int_1(char **argv, t_stack *stack);
void	check_args_int_2(int argc, char **argv, t_stack *stack);
void    check_args_max_int(t_stack *stack);
void    create_list(t_stack *stack);
int     ft_atoi_long(const char *str, t_stack *stack);

void    push_a(t_stack *stack);
void    push_b(t_stack *stack);
void    reverse_rotate_a(t_stack *stack);
void    reverse_rotate_b(t_stack *stack);
void    reverse_rotate_ab(t_stack *stack);
void    rotate_a(t_stack *stack);
void    rotate_b(t_stack *stack);
void    rotate_ab(t_stack *stack);
void    swap_a(t_stack *stack);
void    swap_b(t_stack *stack);
void    swap_ab(t_stack *stack);

void    sort_3_nums(t_stack *stack);
int find_cost(t_stack *stack);
int find_closest_number_to_a(int num_a, t_list *list_b);
int find_opt_moves_a(t_stack *stack, int i);
int find_opt_moves_b(t_stack *stack, int j);
void    push_a_to_b(t_stack *stack);
void    back_to_a(t_stack *stack);
void    optimal_b_to_a(t_stack *stack, int i);
void    push_back_to_a(t_stack *stack);
void    numbers_ordered(t_stack *stack);

#endif