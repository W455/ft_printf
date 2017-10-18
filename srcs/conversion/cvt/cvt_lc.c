/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_lc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/10/17 22:45:31 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	conv_lc(va_list *app, t_flag *env)
{
	wchar_t		buf[2];

	buf[0] = (wchar_t)va_arg(*app, wchar_t);
	buf[1] = 0;
	env->precision = 4;
	put_ls(buf, 4, env);
}
