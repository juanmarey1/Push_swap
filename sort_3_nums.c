/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:04 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/08/26 15:44:05 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	first_smaller_than_second(t_stack *stack, t_list *lst)
{
	if (lst->next->content > lst->next->next->content)
	{
		reverse_rotate_a(stack);
		lst = *stack->stack_a;
		if (lst->next->content < lst->content)
			swap_a(stack);
	}
	else
		return ;
}

void	first_bigger_than_second(t_stack *stack, t_list *lst)
{
	if (lst->content > lst->next->next->content
		&& lst->next->content > lst->next->next->content)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (lst->content > lst->next->next->content
		&& lst->next->content < lst->next->next->content)
		rotate_a(stack);
	else
		swap_a(stack);
}

void	sort_3_nums(t_stack *stack)
{
	t_list	*lst;

	lst = *stack->stack_a;
	if (lst->content < lst->next->content)
		first_smaller_than_second(stack, lst);
	else
		first_bigger_than_second(stack, lst);
}
