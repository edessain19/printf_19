/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:05:18 by edessain          #+#    #+#             */
/*   Updated: 2020/02/20 09:05:44 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_c(t_flag *flag, va_list *ap)
{
	char	c;
	int		min_w;

	min_w = flag->min_w;
	c = va_arg(*ap, int);
	if (min_w > 0 && flag->minus == 0)
	{
		while (min_w > 1)
		{
			ft_putchar(' ', flag);
			min_w--;
		}
		ft_putchar(c, flag);
	}
	else if (min_w > 0 && flag->minus == 1)
	{
		ft_putchar(c, flag);
		while (min_w > 1)
		{
			ft_putchar(' ', flag);
			min_w--;
		}
	}
	else
		ft_putchar(c, flag);
}
