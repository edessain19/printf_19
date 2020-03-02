/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:08:51 by edessain          #+#    #+#             */
/*   Updated: 2020/02/19 15:05:36 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_x(t_flag *flag, va_list *ap)
{
	char			*str;
	unsigned int	nb;
	int				size;

	nb = va_arg(*ap, unsigned int);
	if (flag->prec == 0 && nb == 0)
		str = "";
	else if (flag->convert == 'X')
		str = ft_itoa_base(nb, "0123456789ABCDEF", 16);
	else
		str = ft_itoa_base(nb, "0123456789abcdef", 16);
	if (str == NULL)
		return (ft_free(&str, -1));
	size = ft_strlen_2(str);
	if (flag->prec != -1)
		flag->zpad = 0;
	if (flag->prec < size && (flag->prec != 0 || nb != 0))
		flag->prec = size;
	if (flag->minus == 0)
		print_x_2(flag, str, size);
	else
		print_x_3(flag, str, size);
	if (ft_strncmp(str, "", 1) != 0)
		ft_free(&str, 0);
	return (0);
}

void	print_x_2(t_flag *flag, char *str, int size)
{
	if (flag->zpad == 1)
	{
		while (flag->min_w - size > 0)
		{
			ft_putchar('0', flag);
			flag->min_w--;
		}
		ft_putstr(str, flag);
	}
	else
	{
		while (flag->min_w - flag->prec > 0)
		{
			ft_putchar(' ', flag);
			flag->min_w--;
		}
		while (flag->prec > size)
		{
			ft_putchar('0', flag);
			flag->prec--;
		}
		ft_putstr(str, flag);
	}
}

void	print_x_3(t_flag *flag, char *str, int size)
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
		flag->min_w--;
	}
}
