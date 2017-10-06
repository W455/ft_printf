/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:03:02 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/06 20:29:13 by oukrifa          ###   ########.fr       */
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
    void (*fun_ptr)(va_list *app, struct s_flag *flag);  
    static t_flag env;

    env.i = 0;
    env.n_printed = 0;
    while (*format && env.n_printed >= 0)
    {
        if (*format != '%')
            add_to_buff(&env, *format++);
        else
        {
                if (env.init == 0)
                    init_flag(&env);
                reset_flag(&env);
                get_flags(&env, &format);
                fun_ptr = env.cvt[env.id];
                if (env.cvt[env.id])
                    fun_ptr(&(env.ap), &env);
                else
                    format--;
        }
        }
    write(1, env.buff, env.i);
    va_end(ap);
    return (env.n_printed);
}