/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_check_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:10:12 by edessain          #+#    #+#             */
/*   Updated: 2020/02/28 15:09:28 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->zpad = 0;
	flag->min_w = 0;
	flag->prec = -1;
	flag->convert = 0;
	flag->negatif = 0;
}

void		get_minus_zpad(const char *str, int i, t_flag *flag)
{
	if (str[i] == '-')
		flag->minus = 1;
	else if (str[i] == '0')
		flag->zpad = 1;
}

void		get_min_w(const char *str, int i, t_flag *flag, va_list *ap)
{
	int		nb;

	nb = 0;
	if (str[i] == '*')
		nb = va_arg(*ap, int);
	else if (str[i] >= '1' && str[i] <= '9')
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + str[i] - 48;
			i++;
		}
	if (nb < 0)
	{
		nb = -nb;
		flag->minus = 1;
	}
	flag->min_w = nb;
}

void		get_prec(const char *str, int i, t_flag *flag, va_list *ap)
{
	int		nb;

	nb = 0;
	if (str[i] == '*')
		nb = va_arg(*ap, int);
	else if (str[i] >= '0' && str[i] <= '9')
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + str[i] - 48;
			i++;
		}
	else
		nb = 0;
	if (nb < 0)
		flag->prec = -1;
	else
		flag->prec = nb;
}

int			fill_struct(t_flag *flag, const char *str, int i, va_list *ap)
{
	int leng;

	leng = get_conversion(str, i, flag);
	get_minus_zpad(str, i, flag);
	while (str[i] && (check_conversion(str[i]) == 'z') && i <= leng)
	{
		if (check_flag(str[i], flag) == -1)
			return (-1);
		if (((str[i] >= '1' && str[i] <= '9') || str[i] == '*')
				&& str[i - 1] != '.')
		{
			get_min_w(str, i, flag, ap);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (str[i] == '.')
		{
			i++;
			get_prec(str, i, flag, ap);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		i++;
	}
	return (leng);
}
