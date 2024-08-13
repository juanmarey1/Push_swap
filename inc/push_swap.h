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
    int     contador;
    int     min_moves;
    int     test_moves;
    int     number_in_list_a;
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

int find_cost(t_stack *stack);
int find_closest_number_to_a(int num_a, t_list *list_b);
int find_opt_moves_a(t_stack *stack, int i);
int find_opt_moves_b(t_stack *stack, int i);

#endif