/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:16:02 by edessain          #+#    #+#             */
/*   Updated: 2020/02/17 16:26:41 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_i_5(t_flag *flag, char *str, int size)
{
	if (flag->minus == 0)
	{
		while (flag->min_w - flag->prec > 0)
		{
			ft_putchar(' ', flag);
			flag->min_w--;
		}
		if (flag->negatif == 1)
			ft_putchar('-', flag);
		while (flag->prec - size > 0)
		{
			ft_putchar('0', flag);
			flag->prec--;
		}
		ft_putstr(str, flag);
	}
	else
		print_i_6(flag, str, size);
}

void	print_i_6(t_flag *flag, char *str, int size)
{
	if (flag->negatif == 1)
		ft_putchar('-', flag);
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

void	print_i_zzpad(t_flag *flag, char *str, int size, char c)
{
	if (c == 'b')
	{
		if (flag->negatif == 1)
			ft_putchar('-', flag);
		while (flag->prec > size)
		{
			ft_putchar('0', flag);
			flag->prec--;
		}
		ft_putstr(str, flag);
	}
	else
	{
		if (flag->negatif == 1)
			ft_putchar('-', flag);
		while (flag->min_w > size)
		{
			ft_putchar('0', flag);
			flag->min_w--;
		}
		ft_putstr(str, flag);
	}
}
