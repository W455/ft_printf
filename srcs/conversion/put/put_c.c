/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 00:20:25 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/14 01:26:27 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	put_space(int call, t_flag *env)
{
    if (call == 1)
    {
        while (!FLAG['-'] && !FLAG['0'] && WIDTH > 1)
            add_to_buff(env, ' ');
    }
    else if (call == 2)
    {
        while (FLAG['-'] && WIDTH >= 0)
            add_to_buff(env, ' ');
    }
}

static	void	put_precision_or_0(t_flag *env)
{
	while (WIDTH-- > 1 && FLAG['0'])
		add_to_buff(env, '0');
}

void    put_c(char c, t_flag *env)
{
    WIDTH ? put_space(1, env) : 0;
    put_precision_or_0(env);
    add_to_buff(env, c);
    WIDTH > 0 ? put_space(2, env) : 0;
}