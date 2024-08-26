/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:38:17 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/08/26 14:38:23 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	char		**args;
	t_list		**stack_a;
	t_list		*list_a;
	int			a_nums;
	t_list		**stack_b;
	t_list		*list_b;
	int			b_nums;
	int			atoi_error;
	int			up_a;
	int			up_b;
	int			down_a;
	int			down_b;
	int			up_ab;
	int			down_ab;
	int			up_a_down_b;
	int			down_a_up_b;
	int			common_up;
	int			common_down;
	int			which_case;
	int			movements;
}	t_stack;

void	ft_double_free(char **double_str);
void	ft_error(t_stack *stack);
void	ft_end_program(t_stack *stack);

void	check_args_argc_is_2(char **argv, t_stack *stack);
void	check_args_argc_not_2(int argc, char **argv, t_stack *stack);
void	check_args_max_int(t_stack *stack);
void	check_no_rep_num(char **double_str, t_stack *stack);
void	create_list(t_stack *stack);
int		ft_atoi_long(const char *str, t_stack *stack);

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_ab(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack);

void	sort_4_nums(t_stack *stack);
void	sort_3_nums(t_stack *stack);
void	find_cost(t_stack *stack);
int		find_closest_number_to_a(int num_a, t_list *list_b);
int		find_opt_moves_a(t_stack *stack, int i);
int		find_opt_moves_b(t_stack *stack, int j);
void	push_a_to_b(t_stack *stack);
void	back_to_a(t_stack *stack);
void	optimal_b_to_a(t_stack *stack, int i);
void	push_back_to_a(t_stack *stack);
void	numbers_ordered(t_stack *stack);

#endif
