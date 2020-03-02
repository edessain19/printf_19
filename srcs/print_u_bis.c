/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:16:02 by edessain          #+#    #+#             */
/*   Updated: 2020/02/18 09:00:40 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_u_5(t_flag *flag, char *str, int size)
{
	if (flag->minus == 0)
	{
		while (flag->min_w - flag->prec > 0)
		{
			ft_putchar(' ', flag);
			flag->min_w--;
		}
		while (flag->prec - size > 0)
		{
			ft_putchar('0', flag);
			flag->prec--;
		}
		ft_putstr(str, flag);
	}
	else
		print_u_6(flag, str, size);
}

void	print_u_6(t_flag *flag, char *str, int size)
{
	while (flag->prec - size > 0)
	{
		ft_putchar('0', flag);
		size++;
	}
	ft_putstr(str, flag);
	while (flag->min_w - flag->prec > 0)
	{
		ft_putchar(' ', flag);
		flag->prec++;
	}
}

void	print_u_zzpad(t_flag *flag, char *str, int size, char c)
{
	if (c == 'b')
	{
		while (flag->prec > size)
		{
			ft_putchar('0', flag);
			flag->prec--;
		}
		ft_putstr(str, flag);
	}
	else
	{
		while (flag->min_w > size)
		{
			ft_putchar('0', flag);
			flag->min_w--;
		}
		ft_putstr(str, flag);
	}
}
