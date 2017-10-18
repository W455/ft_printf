/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:03:02 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/18 00:44:21 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     ft_printf(const char *format, ...)
{
        static t_flag env;

        env.i = 0;        
        env.n_printed = 0;
        va_start(env.ap, format);
        format_print(&env, format);
        va_end(env.ap);
        return (env.n_printed);
}

int ft_vprintf(const char *format, va_list ap)
{
    return (ft_vfprintf(stdout, format, ap));
}
 
int     ft_fprintf(FILE *stream, const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    return (ft_vfprintf(stream, format, ap));
}

/*
**  fd = FILE->_file
*/

int ft_vfprintf(FILE *stream, const char *fmt, va_list ap)
{
    static t_flag env;
    
    env.n_printed = 0;
    env.i = 0;
   // env.ap = ap;
    format_print(&env, fmt);
    va_end(env.ap);
    return (env.n_printed);
}