/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:08:29 by edessain          #+#    #+#             */
/*   Updated: 2020/02/20 09:28:05 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

/*
**		structure
*/

typedef struct	s_flag
{
	int			minus;
	int			zpad;
	int			min_w;
	int			prec;
	char		convert;
	int			negatif;
	int			nb_print;
}				t_flag;

/*
**		ft_printf
*/

void			ft_putchar(char c, t_flag *flag);
void			ft_putstr(char *str, t_flag *flag);
int				ft_print(const char *format, va_list *ap, t_flag *flag, int i);
int				ft_printf(const char *form, ...);

/*
**		aux_struct_flag
*/

void			init_flag(t_flag *flag);
void			get_minus_zpad(const char *str, int i, t_flag *flag);
void			get_min_w(const char *str, int i, t_flag *flag, va_list *ap);
void			get_prec(const char *str, int i, t_flag *flag, va_list *ap);
int				fill_struct(t_flag *flag, const char *str, int i, va_list *ap);

/*
**		aux_check_conver
*/

char			check_conversion(char c);
int				get_conversion(const char *str, int i, t_flag *flag);
int				check_flag(char c, t_flag *flag);
int				print_and_count(t_flag *flag, va_list *ap);
int				ft_free(char **string, int i);

/*
**		print flag
*/

void			print_c(t_flag *flag, va_list *ap);

int				print_s(t_flag *flag, va_list *ap);
void			print_s_r(t_flag *flag, char *str);
void			print_s_l(t_flag *flag, char *str);

int				print_i(t_flag *flag, va_list *ap);
void			print_i_dispatch(t_flag *flag, char *str, int size);
void			print_i_2(t_flag *flag, char *str, int size);
void			print_i_3(t_flag *flag, char *str, int size, char c);
void			print_i_4(t_flag *flag, char *str, int size);
void			print_i_5(t_flag *flag, char *str, int size);
void			print_i_6(t_flag *flag, char *str, int size);
void			print_i_zzpad(t_flag *flag, char *str, int size, char c);
char			*ft_strdup_2(const char *s1);

int				print_u(t_flag *flag, va_list *ap);
void			print_u_dispatch(t_flag *flag, char *str, int size);
void			print_u_2(t_flag *flag, char *str, int size);
void			print_u_3(t_flag *flag, char *str, int size, char c);
void			print_u_4(t_flag *flag, char *str, int size);
void			print_u_5(t_flag *flag, char *str, int size);
void			print_u_6(t_flag *flag, char *str, int size);
void			print_u_zzpad(t_flag *flag, char *str, int size, char c);

int				print_p(t_flag *flag, va_list *ap);
void			print_p_2(t_flag *flag, char *str, int size);

void			print_percent(t_flag *flag);

int				print_x(t_flag *flag, va_list *ap);
void			print_x_2(t_flag *flag, char *str, int size);
void			print_x_3(t_flag *flag, char *str, int size);

#endif
