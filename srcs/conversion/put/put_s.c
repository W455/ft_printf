/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:44:42 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/12 01:12:09 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void    put_space(int pos, t_flag *env)
{
    if (pos == 1)
    {
        while (!FLAG['-'] && !FLAG['0'] && 
                env->width > PRECISION)
                add_to_buff(env, ' ');
        FLAG['-'] ? 1 : PRECISION++;
    }
    if (pos == 2)
       while (FLAG['-'] && env->width >= PRECISION + 2)
           add_to_buff(env, ' ');
}

static void    put_value(t_flag *env, char *s)
{
    while (*s && PRECISION-- > 1)
        add_to_buff(env, *s++);  
}

static void    put_0(t_flag *env)
{
    while (env ->width >= PRECISION && FLAG['0'] && !FLAG['-'] && env->n_printed >= 0)
        add_to_buff(env, '0');
}

void    put_s(char *s, t_flag *env)
{
    put_space(1, env);
    put_0(env);
    put_value(env, s);
    put_space(2, env);
}