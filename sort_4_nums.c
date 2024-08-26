/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:11 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/08/26 15:44:13 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	sort_4_nums(t_stack *stack)
{
	stack->stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack->stack_b)
		ft_error(stack);
	*stack->stack_b = NULL;
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
