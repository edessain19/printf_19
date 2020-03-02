/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:05:55 by edessain          #+#    #+#             */
/*   Updated: 2020/02/19 15:10:42 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_s(t_flag *flag, va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char*);
	if (!str)
		str = "(null)";
	if (flag->prec > ft_strlen_2(str))
		flag->prec = ft_strlen_2(str);
	if (flag->prec == -1)
		flag->prec = ft_strlen_2(str);
	if (flag->minus == 1)
		print_s_l(flag, str);
	else
		print_s_r(flag, str);
	return (0);
}

void	print_s_r(t_flag *flag, char *str)
{
	int		i;

	i = 0;
	if (flag->min_w > flag->prec)
	{
		while ((flag->min_w - flag->prec) > 0)
		{
			ft_putchar(' ', flag);
			flag->min_w--;
		}
	}
	while (i < flag->prec)
	{
		ft_putchar(str[i], flag);
		i++;
	}
}

void	print_s_l(t_flag *flag, char *str)
{
	int		i;

	i = 0;
	while (i < flag->prec)
	{
		ft_putchar(str[i], flag);
		i++;
	}
	while (flag->min_w > flag->prec)
	{
		ft_putchar(' ', flag);
		flag->min_w--;
	}
}
