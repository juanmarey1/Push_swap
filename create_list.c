/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:28:52 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/08/26 15:28:53 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	create_list(t_stack *stack)
{
	int		i;
	t_list	*head;
	t_list	*new_lst;

	stack->stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!(stack->stack_a))
		ft_error(stack);
	*stack->stack_a = ft_lstnew(ft_atoi((char *)stack->args[0]));
	if (!(*stack->stack_a))
		ft_error(stack);
	head = *stack->stack_a;
	i = 1;
	while (stack->args[i])
	{
		new_lst = ft_lstnew(ft_atoi((char *)stack->args[i]));
		if (!new_lst)
			ft_error(stack);
		ft_lstadd_back(stack->stack_a, new_lst);
		i++;
	}
	stack->a_nums = i;
	*stack->stack_a = head;
	ft_double_free(stack->args);
}
