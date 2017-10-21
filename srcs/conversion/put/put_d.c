/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 23:45:23 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/20 00:01:46 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

static	void	ft_put_space(int call, int sign, int len, t_flag *env)
{
    if (FLAG['\''] || FLAG[','])
        len += (len + 1) / 3 - sign - (len % 3 == 0 || len % 3 == 2 ? 1 : 0);
    if (call == 1)
    {
        while (!FLAG['-'] && !FLAG['0'] && !FLAG['='] && WIDTH >
        (PRECISION > len ? PRECISION : len) + sign)
        add_to_buff(env, ' ');
        
        while (!FLAG['-'] && !FLAG['0'] && FLAG['='] && WIDTH > len && env->a--
        && WIDTH > (PRECISION > len ? PRECISION : len) + sign)
        add_to_buff(env, ' ');
    }
    else if (call == 2)
    {
        while (!FLAG['='] && FLAG['-'] && WIDTH > 0)
            add_to_buff(env, ' ');
        while (FLAG['='] && !FLAG['-'] && env->b-- > 0 && WIDTH)
            add_to_buff(env, ' ');
    }
}

static	void	ft_put_sign(t_flag *env, int sign)
{
    if (FLAG['#'] && sign)
    {
        add_to_buff(env, '0');
        ID == 'x' || ID == 'p' ? add_to_buff(env, 'x') : 0;
        ID == 'X' ? add_to_buff(env, 'X') : 0;
        ID == 'b' ? add_to_buff(env, 'b') : 0;
        PRECISION >= 0 && ID == 'o' ? (PRECISION -= sign) : 0;
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
    PRECISION = WIDTH;
    FLAG['#'] && ft_memchr("xX", ID, 2) ? PRECISION++ : 0;
    while (PRECISION-- > len)
        add_to_buff(env, '0');
}

static	void	ft_put_value(t_flag *env, int len, char *p)
{
    int a;
    
    a = 0;
    if (env->id == 'c')
        add_to_buff(env, *p++);
    while (*p)
    {
        if (FLAG['\''] && (len - a++) % 3 == 0 && a - 1)
            add_to_buff(env, ' ');
        if (FLAG[','] && (len - a++) % 3 == 0 && a - 1)
            add_to_buff(env, ',');
        add_to_buff(env, *p++);
    }
}
void			put_d(char *p, int len, t_flag *env, int sign)
{
    int l_just;
    
    l_just = FLAG['\''] || FLAG[','] ? len + (len + 1) / 3 - sign - (len % 3 == 0 || len % 3 == 2 ? 1 : 0) : len;
    l_just = l_just > PRECISION ? l_just : PRECISION;
    env->a = (WIDTH - l_just) / 2 + (WIDTH - l_just) % 2 - sign;
    env->b = (WIDTH - l_just) / 2;
    FLAG['#'] && ft_memchr("xX", ID, 2) ? len++ : 0;
    FLAG['#'] && ft_memchr("b", ID, 2) ? WIDTH-- : 0;
    WIDTH ? ft_put_space(1, sign, len, env) : 0;
    sign ? ft_put_sign(env, sign) : 0;
    ft_put_precision_or_0(env, len);
    ft_put_value(env, len, p);
    WIDTH > 0 ? ft_put_space(2, sign, len, env) : 0;
}