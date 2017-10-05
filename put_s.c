/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:44:42 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/06 01:06:30 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void    put_space(int pos, t_flag *env)
{
    if (pos == 1)
    {
        while (!env->flag['-'] && !env->flag['0'] && 
                env->width > env->precision)
                add_to_buff(env, ' ');
        env->flag['-'] ? 1 : env->precision++;
    }
    if (pos == 2)
        while (env->flag['-'] && env->width >= 0)
            add_to_buff(env, ' ');
}

static void    put_value(t_flag *env, char *s)
{
    while (*s && env->precision--)
        add_to_buff(env, *s++);
}

static void    put_0(t_flag *env)
{
    while (env ->width >= env->precision && env->flag['0'] && !env->flag['-'])
        add_to_buff(env, '0');
}

void    put_s(char *s, t_flag *env)
{
    put_space(1, env);
    put_0(env);
    put_value(env, s);
    put_space(2, env);
}