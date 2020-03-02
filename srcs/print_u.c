/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:55:09 by edessain          #+#    #+#             */
/*   Updated: 2020/02/20 09:07:55 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_u(t_flag *flag, va_list *ap)
{
	char				*str;
	int					size;
	unsigned int		nb;

	nb = va_arg(*ap, unsigned long int);
	if (flag->prec == 0 && nb == 0)
		str = "";
	else
	{
		if ((str = ft_itoa_base(nb, "0123456789", 10)) == NULL)
			return (ft_free(&str, -1));
	}
	size = ft_strlen_2(str);
	if (flag->minus == 1)
		flag->zpad = 0;
	if (flag->prec <= ft_strlen_2(str) && flag->min_w <= ft_strlen_2(str))
		ft_putstr(str, flag);
	else
		print_u_dispatch(flag, str, size);
	if (ft_strncmp(str, "", 1) != 0)
		ft_free(&str, 0);
	return (0);
}

void	print_u_dispatch(t_flag *flag, char *str, int size)
{
	if (flag->prec <= size && flag->min_w > size)
		print_u_2(flag, str, size);
	else if (flag->prec > size && flag->min_w <= size)
		print_u_3(flag, str, size, '0');
	else if (flag->prec >= flag->min_w)
		print_u_3(flag, str, size, '0');
	else if (flag->prec < flag->min_w)
		print_u_4(flag, str, size);
}

void	print_u_2(t_flag *flag, char *str, int size)
{
	if (flag->zpad == 1 && flag->prec == -1)
		print_u_zzpad(flag, str, size, 'a');
	else if (flag->minus == 1)
	{
		ft_putstr(str, flag);
		while (flag->min_w - size > 0)
		{
			ft_putchar(' ', flag);
			flag->min_w--;
		}
	}
	else
	{
		while (flag->min_w > size)
		{
			ft_putchar(' ', flag);
			flag->min_w--;
		}
		ft_putstr(str, flag);
	}
}

void	print_u_3(t_flag *flag, char *str, int size, char c)
{
	if (flag->zpad == 1 && flag->prec == -1)
		print_u_zzpad(flag, str, size, 'b');
	else
	{
		while (flag->prec > size)
		{
			ft_putchar(c, flag);
			flag->prec--;
		}
		ft_putstr(str, flag);
	}
}

void	print_u_4(t_flag *flag, char *str, int size)
{
	if (flag->zpad == 1)
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
		print_u_5(flag, str, size);
}
