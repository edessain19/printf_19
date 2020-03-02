/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:30:59 by edessain          #+#    #+#             */
/*   Updated: 2020/02/20 09:10:16 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_p(t_flag *flag, va_list *ap)
{
	char				*str;
	unsigned long long	nb;

	nb = va_arg(*ap, unsigned long long);
	if (nb == 0 && flag->prec == 0)
		str = "";
	else
	{
		if ((str = ft_itoa_base(nb, "0123456789abcdef", 16)) == NULL)
			return (ft_free(&str, -1));
	}
	if (flag->minus == 0)
	{
		while (flag->min_w - ft_strlen_2(str) > 2)
		{
			ft_putchar(' ', flag);
			flag->min_w--;
		}
		ft_putchar('0', flag);
		ft_putchar('x', flag);
		ft_putstr(str, flag);
	}
	else
		print_p_2(flag, str, ft_strlen_2(str));
	return (ft_strncmp(str, "", 1) != 0 ? ft_free(&str, 0) : 0);
}

void	print_p_2(t_flag *flag, char *str, int size)
{
	ft_putchar('0', flag);
	ft_putchar('x', flag);
	ft_putstr(str, flag);
	while (flag->min_w - size > 2)
	{
		ft_putchar(' ', flag);
		flag->min_w--;
	}
}

void	print_percent(t_flag *flag)
{
	char				c;

	if (flag->zpad == 1 && flag->minus == 0)
		c = '0';
	else
		c = ' ';
	if (flag->minus == 0)
	{
		while (flag->min_w > 1)
		{
			ft_putchar(c, flag);
			flag->min_w--;
		}
		ft_putchar('%', flag);
	}
	else
	{
		ft_putchar('%', flag);
		while (flag->min_w > 1)
		{
			ft_putchar(c, flag);
			flag->min_w--;
		}
	}
}
