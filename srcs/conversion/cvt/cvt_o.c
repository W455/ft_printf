/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 23:31:18 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/17 00:12:35 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
static char		*cvt_u(unsigned long long nbr, char *buf)
{
	char				*p;

	p = buf + 44;
	*p = 0;
	if (nbr == 0)
		*--p = '0';
	while (nbr)
	{
		*--p = nbr % 10 + '0';
		nbr /= 10;
	}
	return (p);
}
*/

void			conv_o(va_list *ap, t_flag *env)
{
	unsigned long long		nbr;
	char					buf[44];
	char					*p;

	nbr = ft_printf_get_arg(ap, env);
	nbr = (env->flag['l'] || env->flag['L'] || env->flag['z'] ||
			env->flag['j']) ? nbr : (unsigned int)nbr;
    ft_itoa_base(nbr, 8, BASE_MAJ, buf, env);
    if (PRECISION == 0 && *buf == '0')
        return ;
	put_d(buf, ft_strlen(buf), env, 0);
}
