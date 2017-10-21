/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 23:31:18 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/18 23:39:56 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			conv_o(va_list *ap, t_flag *env)
{
	unsigned long long		nbr;
	char					buf[44];
	char					*p;

	nbr = ft_printf_get_arg(ap, env);
	nbr = (env->flag['l'] || env->flag['L'] || env->flag['z'] ||
			env->flag['j']) ? nbr : (unsigned int)nbr;
    ft_itoa_base(nbr, 8, BASE_MAJ, buf, env);
    if (PRECISION == 0 && nbr == 0 && !WIDTH)
        return ;
    if (PRECISION == 0 && nbr == 0 && WIDTH)
        *buf = ' ';
	put_d(buf, ft_strlen(buf), env, FLAG['#'] && *buf ? 1 : 0);
}
