/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/10/19 23:57:33 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_cvt_c(va_list *app, t_flag *flag)
{
	char	buf[2];

    buf[0] = (unsigned char)va_arg(*app, unsigned int);
    printf("->%c<-\n", buf[0]);
	buf[1] = 0;
	flag->precision = 0;
	ft_printf_putd(buf, 1, flag, 0);
}
