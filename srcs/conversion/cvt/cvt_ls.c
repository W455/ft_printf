/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:02:51 by gduron            #+#    #+#             */
/*   Updated: 2017/10/17 22:46:02 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	null_pointer_case(t_flag *flag)
{
	add_to_buff(flag, '(');
	add_to_buff(flag, 'n');
	add_to_buff(flag, 'u');
	add_to_buff(flag, 'l');
	add_to_buff(flag, 'l');
	add_to_buff(flag, ')');
}

static int	wstrlen(wchar_t *p)
{
	long	i;

	i = 0;
	while (*p)
	{
		i += 4;
		i = *p <= 0xFFFF ? i - 1 : i;
		i = *p <= 0x7FF ? i - 1 : i;
		i = *p <= 0x7F ? i - 1 : i;
		p++;
	}
	return (i);
}

void		conv_ls(va_list *app, t_flag *env)
{
	wchar_t	*p;
	int		len;

	p = va_arg(*app, wchar_t *);
	if (!p)
	{
		null_pointer_case(env);
		return ;
	}
	len = wstrlen(p);
	if (env->precision > len || env->precision < 0)
		env->precision = len;
	p ? put_ls(p, 0, env) : 0;
}
