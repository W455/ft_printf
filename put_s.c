/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:44:42 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/05 23:09:09 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void    put_space(int pos, t_flag *env)
{
    if (pos == 1)
        while (!env->flag['-'] && !env->flag['0'] && 
                env->width > env->precision)
            add_to_buff(env, ' ');
    if (pos == 2)
        while (!env->flag['-'] && !env->flag['0'] && 
                env->width > 0)
            add_to_buff(env, ' ');
}

static void    put_value(t_flag *env, char *s)
{
    while (*s && env->precision--)
        add_to_buff(env, *s++);
}

static void    put_s(char *s, t_flag *env)
{
    put_space(1, env);
    put_value(env, s);
    put_space(2, env);
}

static void     null_ptr(t_flag *env)
{
    add_to_buff(env, '(');
	add_to_buff(env, 'n');
	add_to_buff(env, 'u');
	add_to_buff(env, 'l');
	add_to_buff(env, 'l');
	add_to_buff(env, ')');
}
 
void    conv_s(/*va_list *ap*/char * st, t_flag *env)
{
    char    *s;

    s = st;//va_arg(*ap, char *);
    if (!s)
    {
        null_ptr(env);
        return ;
    }
    if (env->precision > ft_strlen(s) || env->precision < 0)
        env->precision = ft_strlen(s);
    put_s(s, env);
}
