/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:10:59 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/09 17:48:16 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			reset_flag(t_flag *env)
{
    env->flag['\''] = 0;    
	env->flag['l'] = 0;
	env->flag['L'] = 0;
	env->flag['h'] = 0;
	env->flag['H'] = 0;
	env->flag['z'] = 0;
	env->flag['j'] = 0;
    env->flag['0'] = 0;
	env->flag['+'] = 0;    
	env->flag['-'] = 0;
	env->flag[' '] = 0;
	env->flag['.'] = 0;
    env->flag['*'] = 0;	
    env->flag['#'] = 0;
    env->flag['$'] = 0; 
    env->precision = -1;    
	env->width = 0;
	env->id = 0;
}

static	void	init_cvt(t_flag *env)
{
    /*
    env->cvt['d'] = &conv_d;
    env->cvt['D'] = &conv_d;
	env->cvt['i'] = &conv_d;
	env->cvt['%'] = &conv_pourcent;
    env->cvt['n'] = &conv_n;
    env->cvt['u'] = &conv_u;    
	env->cvt['U'] = &conv_u;
	env->cvt['o'] = &conv_o;
	env->cvt['O'] = &conv_o;
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
    env->cvt['s'] = &conv_s;    
}

void			init_flag(t_flag *flag)
{
	flag->init++;
	init_cvt(flag);
}