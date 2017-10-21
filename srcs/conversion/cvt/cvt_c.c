/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 00:22:58 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/19 23:59:37 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    conv_c(va_list *ap, t_flag *env)
{
    char buf[2];

    buf[0] = (unsigned char)va_arg(*ap, unsigned int);
    buf[1] = 0;
    PRECISION = 0;
    put_d(buf, 1, env, 0);
}
