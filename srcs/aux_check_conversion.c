/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_check_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:39:31 by edessain          #+#    #+#             */
/*   Updated: 2020/02/19 15:26:00 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	check_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return ('c');
	else
		return ('z');
}

int		get_conversion(const char *str, int i, t_flag *flag)
{
	while (check_conversion(str[i]) != 'c')
		i++;
	flag->convert = str[i];
	return (i);
}

int		check_flag(char c, t_flag *flag)
{
	if (ft_isdigit(c) == 1 || c == '-' || c == '*' || c == '.' || c == 'c'
			|| c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		flag->convert = 0;
	return (-1);
}

int		print_and_count(t_flag *flag, va_list *ap)
{
	if (flag->convert == 'c')
		print_c(flag, ap);
	else if (flag->convert == 's')
		return (print_s(flag, ap));
	else if (flag->convert == 'p')
		return (print_p(flag, ap));
	else if (flag->convert == 'd' || flag->convert == 'i')
		return (print_i(flag, ap));
	else if (flag->convert == 'u')
		return (print_u(flag, ap));
	else if (flag->convert == 'x' || flag->convert == 'X')
		return (print_x(flag, ap));
	else if (flag->convert == '%')
		print_percent(flag);
	return (0);
}

int		ft_free(char **string, int i)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
	return (i);
}
