/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 22:47:44 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/17 23:46:29 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_len(unsigned long long nbr, int base, t_flag *env)
{
	int len;

	len = 0;
	while (nbr / base && len++ >= 0)
        nbr /= base;
	return (len + 1);
}

char	        *ft_itoa_base(unsigned long long nb, int base, 
    char *basef, char *buf, t_flag *env)
    {
        int             i;
 
	i = ft_len(nb, base, env);
    buf[i--] = '\0';
	while (i >= 0)
	{
        buf[i--] = basef[nb % base];
		nb /= base;
    }
	return (buf);
}
