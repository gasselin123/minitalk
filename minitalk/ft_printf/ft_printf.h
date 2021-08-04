/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:47:28 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/29 10:27:15 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>

typedef struct s_flags
{
	int						width;
	int						minus;
	int						zero;
	int						dot;
	int						star;
	int						plus;
	int						space;
	int						hashtag;
	int						sign;
	int						conv;
	char					conv2[4];
	int						length;
	char					pad;
	char					*str;
	long long int			lli;
	unsigned long long int	ulli;
}							t_flags;

typedef struct s_convfeg
{
	long double				nb;
	unsigned long long int	ulli;
	unsigned long long int	int_part;
	long double				dec_part;
	unsigned long long int	dec_int;
	int						dec_int_size;
	char					*a;
	char					*a2;
	char					*a3;
	char					*d;
	char					*d2;
	char					*tmp;
	char					e[5];
	int						e_nbr;
	int						size;
	int						dot_minus;
	size_t					strlen;
}				t_convfeg;

int				ft_printf(const char *format, ...);

void			ft_parser(const char *format, va_list arg_list);
int				ft_parse_flags(const char *str, int i, t_flags *flags,
					va_list arg_list);
int				ft_parse_size(const char *str, int *i, t_flags *flags);
void			ft_formater(int c, t_flags flags, va_list arg_list);

int				ft_isconvt(int c);
int				ft_isflags(int c);
int				ft_isdigit(int c);

void			ft_parse_idu(int c, va_list arg_list, t_flags flags);
void			ft_print_unbr(va_list arg_list, t_flags flags);
void			ft_print_char(va_list arg_list, t_flags flags);
void			ft_print_str(va_list arg_list, t_flags flags);
void			ft_print_ptr(va_list arg_list, t_flags flags);
void			ft_print_hex(va_list arg_list, t_flags flags);
void			ft_print_pct(t_flags flags);
void			ft_print_nil(va_list arg_list, t_flags flags);
void			ft_print_feg(const char c, va_list arg_list, t_flags flags);
t_convfeg		ft_print_f(t_convfeg dbl, t_flags flags);
t_convfeg		ft_print_e(t_convfeg dbl, t_flags flags);
void			ft_print_g(t_convfeg dbl, t_flags flags);
void			ft_print_dbl(t_convfeg dbl, t_flags flags);

t_flags			ft_flag_minus(t_flags flags);
t_flags			ft_flag_digit(char c, t_flags flags);
int				ft_flag_dot(const char *str, int i, t_flags *flags,
					va_list arg_list);
t_flags			ft_flag_width(va_list arg_list, t_flags flags);
t_flags			ft_flag_plus(t_flags flags);
void			ft_print_flags(t_flags flags);

void			ft_treat_width(int width, int minus, int zero);
long double		ft_pow(long double n, unsigned int pow);
int				ft_treat_infnan(double d, t_flags flags);
t_convfeg		ft_ftoa(t_convfeg dbl, t_flags flags);
t_flags			ft_treat_sign(t_flags flags);

void			ft_putchar(char c);
void			ft_putunschar(unsigned char c);
void			ft_putstr(char *str);
void			ft_putnstr(char *str, int n);
void			ft_putwstr(const wchar_t *s);
void			ft_putwchar(wint_t c);

void			ft_putunbr(unsigned long long int n);
void			ft_putunbr_base(unsigned long long int nb, char *base);

char			*ft_uitoa(unsigned int n);
char			*ft_ullitoa(unsigned long long int n);

size_t			ft_printed(int n, int reset);
//size_t			ft_strlen(const char *s);

int				get_shift(wint_t c);
unsigned int	get_mask(wint_t c);
unsigned int	get_header(wint_t c);
size_t			ft_wchar_size(wint_t c);

#endif
