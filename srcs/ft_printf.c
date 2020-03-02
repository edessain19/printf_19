/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:46:37 by edessain          #+#    #+#             */
/*   Updated: 2020/02/28 15:25:17 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr(char *str, t_flag *flag)
{
	while (*str != '\0')
	{
		ft_putchar(*str, flag);
		str++;
	}
}

void	ft_putchar(char c, t_flag *flag)
{
	write(1, &c, 1);
	flag->nb_print++;
}

int		ft_print(const char *format, va_list *ap, t_flag *flag, int i)
{
	int		j;

	while (format[i])
	{
		if (format[i] == '%')
		{
			init_flag(flag);
			j = i;
			i = fill_struct(flag, format, i + 1, ap);
			if (i != -1)
			{
				if (print_and_count(flag, ap) == -1)
					return (-1);
			}
			else
			{
				ft_putchar(format[j], flag);
				i = j;
			}
		}
		else
			ft_putchar(format[i], flag);
		i++;
	}
	return (flag->nb_print);
}

int		ft_printf(const char *form, ...)
{
	char		*f;
	int			nb;
	va_list		ap;
	t_flag		flag;

	init_flag(&flag);
	flag.nb_print = 0;
	f = (char*)form;
	va_start(ap, form);
	if ((nb = ft_print(f, &ap, &flag, 0)) == -1)
		return (-1);
	va_end(ap);
	return (nb);
}
/*
**int		main()
**{
**	printf("%.03s\n", NULL);
**	ft_printf("%.03s\n", NULL);
**	return (0);
**}
*/
