/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_flag.c                                        :+:      :+:     :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:10:50 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/18 17:10:53 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void			reset_flag(t_flag *env)
{
    FLAG['\''] = 0;    
	FLAG['l'] = 0;
	FLAG['L'] = 0;
	FLAG['h'] = 0;
	FLAG['H'] = 0;
	FLAG['z'] = 0;
	FLAG['j'] = 0;
    FLAG['0'] = 0;
	FLAG['+'] = 0;    
	FLAG['-'] = 0;
	FLAG[' '] = 0;
	FLAG['.'] = 0;
    FLAG['*'] = 0;
    FLAG['#'] = 0;
    FLAG['$'] = 0;
    FLAG[','] = 0;
    FLAG['='] = 0;
    PRECISION = -1;
	WIDTH = 0;
    ID = 0;
    env->a = 0;
    env->b = 0;
}

static	void	init_cvt(t_flag *env)
{
    /*
    env->cvt['n'] = &conv_n;
    env->cvt['e'] = &conv_e;
    env->cvt['E'] = &conv_E; 
    env->cvt['g'] = &conv_g;
    env->cvt['G'] = &conv_g;
    */    
	env->cvt['p'] = &conv_x;
	env->cvt['C'] = &conv_lc;
	env->cvt['S'] = &conv_ls;
    env->cvt['b'] = &conv_b;
	env->cvt['X'] = &conv_X;
	env->cvt['x'] = &conv_x;
	env->cvt['O'] = &conv_o;
	env->cvt['o'] = &conv_o;
    env->cvt['u'] = &conv_u;    
	env->cvt['U'] = &conv_u;
    env->cvt['s'] = &conv_s;    
	env->cvt['c'] = &conv_c;
    env->cvt['D'] = &conv_d;
    env->cvt['d'] = &conv_d;
	env->cvt['i'] = &conv_d;
    env->cvt['%'] = &conv_mod;
}

void			init_flag(t_flag *env)
{
	env->init++;
	init_cvt(env);
}