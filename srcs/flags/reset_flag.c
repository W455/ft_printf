/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:10:59 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/12 01:17:50 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_put_space(int call, int s_len, int len, t_flag *env)
{
	if (call == 1)
	{
		while (!FLAG['-'] && !FLAG['0'] && env->width >
				(PRECISION > len ? PRECISION : len) + s_len)
			add_to_buff(flag, ' ');
	}
	else if (call == 2)
	{
		while (FLAG['-'] && env->width > 0)
			add_to_buff(flag, ' ');
	}
}

long long	get_unsigned(va_list *ap, t_flag *env)
{
	if (FLAG['z'])
		return (va_arg(*ap, size_t));
	if (FLAG['j'])
		return (va_arg(*ap, uintmax_t));
	if (FLAG['L'])
		return (va_arg(*ap, unsigned long long));
	if (FLAG['l'])
	{
		return (ID == 'c' ? va_arg(*ap, wchar_t)
				: va_arg(*ap, unsigned long));
	}
	if (FLAG['h'])
		return ((unsigned short)va_arg(*ap, unsigned int) & 4294967295);
	if (FLAG['H'])
		return ((unsigned char)va_arg(*ap, unsigned int) & 4294967295);
	return (va_arg(*ap, unsigned int) & 4294967295);
}

long long	ft_printf_get_arg(va_list *ap, t_flag *env)
{
	if (ID == 'o' || ID == 'x' || flag->id == 'X' ||
			ID == 'u')
		return (get_unsigned(ap, env));
	else
	{
		if (FLAG['z'])
			return (va_arg(*ap, size_t));
		if (FLAG['j'])
			return (va_arg(*ap, intmax_t));
		if (FLAG['L'])
			return (va_arg(*ap, long long));
		if (FLAG['l'])
			return (va_arg(*ap, long));
		if (FLAG['h'])
			return ((short)va_arg(*ap, int) & 4294967295);
		if (FLAG['H'])
			return ((signed char)va_arg(*ap, int) & 4294967295);
	}
	return (va_arg(*ap, int) & 4294967295);
}
static	void	ft_put_sign(t_flag *env, int s_len)
{
	if (FLAG['#'] && s_len)
	{
		add_to_buff(flag, '0');
		ID == 'x' || ID == 'p' ? add_to_buff(env, 'x') : 0;
		ID == 'X' ? add_to_buff(env, 'X') : 0;
		ID == 'b' ? add_to_buff(env, 'b') : 0;
		PRECISION >= 0 && ID == 'o' ?
			(PRECISION -= s_len) : 0;
	}
	else
	{
		FLAG[' '] ? add_to_buff(env, ' ') : 0;
		FLAG['+'] == 1 ? add_to_buff(env, '+') : 0;
		FLAG['+'] == 2 ? add_to_buff(env, '-') : 0;
	}
}

static	void	ft_put_precision_or_0(t_flag *env, int len)
{
	if (PRECISION == -1 && FLAG['0'])
		PRECISION = env->width;
	while (PRECISION-- > len)
		add_to_buff(flag, '0');
}

static	void	ft_put_value(t_flag *env, char *p)
{
	if (ID == 'c')
		add_to_buff(env, *p++);
	while (*p)
		add_to_buff(flag, *p++);
}

void			ft_printf_putd(char *p, int len, t_flag *env, int s_len)
{
	env->width ? ft_put_space(1, s_len, len, env) : 0;
	s_len ? ft_put_sign(env, s_len) : 0;
	ft_put_precision_or_0(env, len);
	ft_put_value(env, p);
	env->width > 0 ? ft_put_space(2, s_len, len, env) : 0;
}

static	char	*cvt_d1(unsigned long long nbr, char *buf)
{
	char	*p;

	p = buf + 44;
	*p = 0;
	if (nbr == 0)
		*--p = '0';
	while (nbr)
	{
		*--p = nbr % 10 + '0';
		nbr /= 10;
	}
	return (p);
}

void			conv_d(va_list *app, t_flag *env)
{
	long long		nbr;
	char			buf[44];
	char			*p;
	int				s_len;

	s_len = 0;
	nbr = 0;
	nbr = ft_printf_get_arg(app, env);
	nbr = (FLAG['l'] || FLAG['L'] || FLAG['z'] ||
			FLAG['j']) ? nbr : (int)nbr;
	p = cvt_d1(nbr > 0 ? nbr : -nbr, buf);
	if (nbr <= 4294967295 && !(FLAG['l'] || FLAG['L'] ||
				FLAG['z'] || FLAG['j']))
	{
		(int)nbr < 0 ? FLAG['+'] = 2 : 0;
		(int)nbr < 0 ? FLAG[' '] = 0 : 0;
	}
	else
	{
		nbr < 0 ? FLAG['+'] = 2 : 0;
		nbr < 0 ? FLAG[' '] = 0 : 0;
	}
	FLAG['+'] || FLAG[' '] ? s_len = 1 : 0;
	PRECISION == 0 && *p == '0' ? p = (buf + sizeof(buf)) : 0;
	ft_printf_putd(p, (buf + sizeof(buf)) - p, env, s_len);
}


void			reset_flag(t_flag *env)
{
    FLAG['\''] = 0;    
	FLAG['l'] = 0;
	FLAG['L'] = 0;
	FLAG['h'] = 0;
	FLAG['H'] = 0;
	FLAG['z'] = 0;
	FLAG['j'] = 0;
    FLAG['0'] = 0;
	FLAG['+'] = 0;    
	FLAG['-'] = 0;
	FLAG[' '] = 0;
	FLAG['.'] = 0;
    FLAG['*'] = 0;	
    FLAG['#'] = 0;
    FLAG['$'] = 0; 
    PRECISION = -1;    
	env->width = 0;
	ID = 0;
}

static	void	init_cvt(t_flag *env)
{
    /*
    env->cvt['D'] = &conv_d;
	env->cvt['i'] = &conv_d;
	env->cvt['%'] = &conv_pourcent;
    env->cvt['n'] = &conv_n;
    env->cvt['u'] = &conv_u;    
	env->cvt['o'] = &conv_o;
	env->cvt['O'] = &conv_o;
	env->cvt['U'] = &conv_u;
	env->cvt['x'] = &conv_x;
	env->cvt['X'] = &conv_x;
	env->cvt['c'] = &conv_c;
	env->cvt['s'] = &conv_s;
	env->cvt['p'] = &conv_x;
	env->cvt['C'] = &conv_lc;
	env->cvt['S'] = &conv_ls;
    env->cvt['b'] = &conv_b;
    env->cvt['e'] = &conv_e;
    env->cvt['E'] = &conv_E; 
    env->cvt['g'] = &conv_g;
    env->cvt['G'] = &conv_g;
    */
}

void			init_flag(t_flag *env)
{
    env->cvt['s'] = &conv_s;    
    env->cvt['d'] = &conv_d;
	//flag->init++;
	//init_cvt(flag);
}