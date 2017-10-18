/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 23:46:55 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/18 23:15:03 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			conv_d(va_list *ap, t_flag *env)
{
	long long		nbr;
	char			buf[44];
	int				sign;

    ft_bzero(buf, 44);
    nbr = ft_printf_get_arg(ap, env);
	nbr = (FLAG['l'] || FLAG['L'] || FLAG['z'] ||
			FLAG['j']) ? nbr : (int)nbr;
	ft_itoa_base(nbr > 0 ? nbr : -nbr, 10, BASE_MAJ, buf, env);
	if (nbr <= 4294967295 && !(FLAG['l'] || FLAG['L'] ||
				FLAG['z'] || FLAG['j']))
	{
		(int)nbr < 0 ? FLAG['+'] = 2 : 0;
		(int)nbr < 0 ? FLAG[' '] = 0 : 0;
	}
	else
	{
		nbr < 0 ? FLAG['+'] = 2 : 0;
		nbr < 0 ? FLAG[' '] = 0 : 0;
	}
	sign = (FLAG['+'] || FLAG[' ']) ? 1 : 0;
    if (PRECISION == 0 && *buf == '0' && !WIDTH)
        return;
    if (PRECISION == 0 && nbr == 0 && WIDTH)
        *buf = ' ';
	put_d(buf, ft_strlen(buf), env, sign);
}