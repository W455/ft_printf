/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:05:38 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/06 01:33:11 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void     null_ptr(t_flag *env)
{
    add_to_buff(env, '(');
	add_to_buff(env, 'n');
	add_to_buff(env, 'u');
	add_to_buff(env, 'l');
	add_to_buff(env, 'l');
	add_to_buff(env, ')');
}
 
void    conv_s(va_list *ap, t_flag *env)
{
    char    *s;

    s = va_arg(*ap, char *);
    if (!s)
    {
        null_ptr(env);
        return ;
    }
    if (env->precision > ft_strlen(s) || env->precision < 0)
        env->precision = ft_strlen(s);
    put_s(s, env);
}