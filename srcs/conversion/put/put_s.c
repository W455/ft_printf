/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:44:42 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/16 22:17:50 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_put_space(int call, int len, t_flag *env)
{
	if (call == 1)
	{
		while (!FLAG['='] && !env->flag['-'] && !env->flag['0'] && WIDTH >
				env->precision)
            add_to_buff(env, ' ');
        while (env->flag['='] && !env->flag['0'] && WIDTH >
            env->precision && env->a--)
            {
            add_to_buff(env, ' ');
            }
	}
	if (call == 2)
	{
		while (env->flag['-'] && WIDTH > 0)
			add_to_buff(env, ' ');
		while (env->flag['='] && WIDTH > 0 && env->b--)
			add_to_buff(env, ' ');
	}
}

static	void	ft_put_precision_or_0(t_flag *env)
{
	while (env->precision > 0 && env->flag['0'])
	{
		add_to_buff(env, '0');
		env->precision--;
	}
}

static	void	ft_put_value(t_flag *env, char *p)
{
	while (*p && (env->flag['.'] ? env->precision-- : 1))
		add_to_buff(env, *p++);
}

void			put_s(char *p, t_flag *env)
{
    int len;

    len = (ft_strlen(p) >= PRECISION) ? PRECISION : ft_strlen(p);
    env->a = (WIDTH - len) / 2 + (WIDTH - len) % 2;
    env->b = (WIDTH - len) / 2;
	ft_put_space(1, len, env);
	ft_put_precision_or_0(env);
	ft_put_value(env, p);
	ft_put_space(2, len, env);
}