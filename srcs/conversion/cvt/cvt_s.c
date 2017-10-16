/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:05:38 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/13 18:48:10 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

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
    (PRECISION > (int)ft_strlen(s) || PRECISION < 0) ? 
        PRECISION = (int)ft_strlen(s) : 0;
    s ? put_s(s, env) : 0;
}