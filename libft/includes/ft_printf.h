/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:30:32 by bnigellu          #+#    #+#             */
/*   Updated: 2019/08/02 14:58:26 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_index
{
	int				i;
	int				i1;
	int				i2;
	int				cloud;
}					t_index;

typedef struct		s_form
{
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				zero;
	long	int		width;
	long	int		prec;
	char			mod[3];
	char			type;
}					t_form;

typedef union
{
	double			d;
	struct
	{
		size_t		mantisa : 52;
		size_t		exponent : 11;
		size_t		sign : 1;
	}				parts;
}					t_double_cast;

typedef struct		s_double
{
	char			*frac;
	char			*mantisa;
	char			*first_2;
	char			*second_int_2;
	char			*second_frac_2;
	char			*integer;
	size_t			length;
}					t_double;

int					init(t_form *per, char *s);
int					mod_di(va_list *ptr, t_form *per);
int					mod_u(va_list *ptr, t_form *per);
int					mod_o(va_list *ptr, t_form *per);
int					mod_x(va_list *ptr, t_form *per);

int					perec(t_form *per);
int					fun_c(int sym, t_form *per);
int					fun_s(char *str, t_form *per);
int					fun_p(char *str, t_form *per);
int					fun_di(char *str, t_form *per);
int					fun_u(char *str, t_form *per);
int					fun_o(char *str, t_form *per);
int					fun_x(char *str, t_form *per);
int					fun_f(double num, t_form *per);

void				print_and_free(char **buf, char **str, char t);
void				minus(char **buf, char *s, int n, int w);
void				hminus(char **buf, char *s, int fl, int w);
void				zero(char **buf, char *s, int n, int w);
void				zero_num(char **buf, char *s, int n, int w);
int					fun_width(int w, char **buf);
void				width_num(int w, char **buf, char *str);
void				w_cpy(char **buf, char *str, int w, int n);
int					s_prec(char **str, t_form *per, char *fl);
void				p_without_flags(char **buf, char *str, t_form *per, int l);
int					p_zero(char **buf, t_form *per);
void				di_minus(char **buf, int fl, t_form *per);
int					fun_zero(char **buf, t_form *per);
int					di_case_else(char **buf, char *str, t_form *per, int l);
int					u_case_else(char **buf, char *str, int l);
int					o_case_else(char **buf, char *str, t_form *per, int l);
int					count_l(t_form *per, int *l);
void				x_zero(char **buf, char *str, t_form *per, int l);
int					x_case_else(char **buf, char *str, t_form *per, int l);
void				flags_dot(int i, int *fl, int *fl1, int *fl2);
void				flags_num(int i, int *fl, int *fl1, int *fl2);

void				second_addend(t_double *list, t_double_cast d1);
void				integer(t_double *list);
char				*summ(char *str1, char *str2);
void				fraction(t_double *list);
char				*beuty_double(t_form *per, t_double *list,
		t_double_cast d1);
void				d_copy(char **str, t_double *list, t_form *per,
		t_double_cast d1);

#endif
