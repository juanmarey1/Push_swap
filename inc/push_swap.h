#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "messages.h"

typedef struct s_stack_a
{
    char    **args;
    t_list  **list;
}   t_stack_a;

typedef struct s_stack_b
{
    t_list  **list;
}   t_stack_b;

void    ft_double_free(char **double_str);
void    ft_error(char *str);

void    check_args_int_1(char **argv, t_stack_a *stack_a);
void	check_args_int_2(int argc, char **argv, t_stack_a *stack_a);
void    check_args_max_int(t_stack_a *stack_a);

#endif