/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:03:02 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/05 19:23:02 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int ft_printf(const char *format, ...);
// printf de base 
int ft_fprintf(FILE *stream, const char *format, ...);
// printf ou on choisit la sortie
int ft_sprintf(char *str, const char *format, ...);
// printf dans un buffer str[]
int ft_snprintf(char *str, size_t size, const char *format, ...);
// printf dans un buffer str[] ou on ecrit sur max size - 1. finir par \0

//envoie dune va lsit ou lieu des ...
int ft_vprintf(const char *format, va_list ap);
int ft_vfprintf(FILE *stream, const char *format, va_list ap);
int ft_vsprintf(char *str, const char *format, va_list ap); 
int ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);

int     ft_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    return (ft_vfprintf(stdout, format, ap));
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

int ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
    t_flag flag;

    flag.n_printed = 0;
    void (*fun_ptr)(va_list *app, struct s_flag *flag);
    
        flag->i = 0;
        while (*fmt && flag->printed_char >= 0)
        {
            if (*fmt != '%' || *(++fmt) == '%')
                add_to_buff(flag, *fmt++);
            else
            {
                if (flag->init == 0)
                    init_flag(flag);
                reset_flag(flag);
                get_flags(flag, &fmt);
                fun_ptr = flag->cvt[flag->id];
                if (flag->cvt[flag->id])
                    fun_ptr(&(flag->ap), flag);
                else
                    fmt--;
            }
        }
        write(1, flag->buff, flag->i);
        flag->i = 0;
    va_end(ap);
    return (flag.n_printed);
}