/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:37:38 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 15:43:07 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char c;
	ft_printf("Introduce tu dígito ASCII\n");
	scanf("%c", &c);
	if (isascii(c) == 0)
		ft_printf("%c is not ascii\n", c);
	else
		ft_printf("%c is ascii\n", c);
	if (ft_isascii(c) == 0)
		ft_printf("%c is not ascii\n", c);
	else
		ft_printf("%c is ascii\n", c);
	ft_printf("%d\n", isascii(c));
	ft_printf("%d\n", ft_isascii(c));
	return (0);
}     
*/
