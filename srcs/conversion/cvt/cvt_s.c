/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:05:38 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/09 21:47:18 by oukrifa          ###   ########.fr       */
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
    char    *end;

    s = va_arg(*ap, char *);       
    if (!s)
    {
        null_ptr(env);
        return ;
    }
    while (*end)
        end++;

        if (env->precision > (int)ft_strlen(s))
            env->precision = (int)ft_strlen(s);
        if (env->precision < 0)
            env->precision = 0;
    //printf("\n=== precision = %d et width = %d.\n", env->precision, env->width);
    s ? put_s(s, env) : 0;
}