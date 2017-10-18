/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 00:22:58 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/18 18:03:13 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    conv_c(va_list *ap, t_flag *env)
{
    char c;
    char buf[2];

    c = (char)va_arg(*ap, int);
    buf[0] = c;
    buf[1] = 0;
    PRECISION = 1;
    put_s(buf, env);
}
