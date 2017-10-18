/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 00:17:37 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/17 23:46:18 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	get_unsigned(va_list *ap, t_flag *env)
{
    if (FLAG['z'])
        return (va_arg(*ap, size_t));
	if (FLAG['j'])
        return (va_arg(*ap, uintmax_t));
	if (FLAG['L'])
        return (va_arg(*ap, unsigned long long));
	if (FLAG['l'])
	{
        return (ID == 'c' ? va_arg(*ap, wchar_t)
        : va_arg(*ap, unsigned long));
	}
	if (FLAG['h'])
        return ((unsigned short)va_arg(*ap, unsigned int) & 4294967295);
	if (FLAG['H'])
        return ((unsigned char)va_arg(*ap, unsigned int) & 4294967295);
	return (va_arg(*ap, unsigned int) & 4294967295);
}

long long	ft_printf_get_arg(va_list *ap, t_flag *env)
{
    if (ID == 'o' || ID == 'x' || env->id == 'X' ||
    ID == 'u' || ID == 'c' || ID == 'b')
		return (get_unsigned(ap, env));
    else
    {
        if (FLAG['z'])
		return (va_arg(*ap, size_t));
        if (FLAG['j'])
		return (va_arg(*ap, intmax_t));
        if (FLAG['L'])
		return (va_arg(*ap, long long));
        if (FLAG['l'])
		return (va_arg(*ap, long));
        if (FLAG['h'])
		return ((short)va_arg(*ap, int) & 4294967295);
        if (FLAG['H'])
		return ((signed char)va_arg(*ap, int) & 4294967295);
    }
    return (va_arg(*ap, int) & 4294967295);
}
