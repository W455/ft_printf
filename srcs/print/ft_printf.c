/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:03:02 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/17 00:47:07 by oukrifa          ###   ########.fr       */
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

int main(void)
{
    //ft_printf(".%10.2'Li.\n", 0);
    //ft_printf(".%10.2'Li.\n", 1);
    //ft_printf(".%10.2'Li.\n", 12);
    //ft_printf(".%10.2'Li.\n", 123);
    //ft_printf(".%10.2'Li.\n", 1234);
    //ft_printf(".%10.2'Li.\n", 12345);
    //ft_printf(".%10.2'Li.\n", 123456);
    //ft_printf(".%10.2'Li.\n", 1234567);
    //ft_printf(".%10.2'Li.\n", 12345678);
    //ft_printf(".%10.2'Li.\n", 123456789);
    //ft_printf(".%10.2'Li.\n", 1234567890);
    //ft_printf(".%10.2'Li.\n", 12345678901);
    //ft_printf(".%10.2'Li.\n", 123456789012);
    //ft_printf(".%10.2'Li.\n", 1234567890123);
    //printf(".%+10.2i.\n", 123456);
    //ft_printf(".%=,+10u.\n", 12345);
    ft_printf("my .%#15.4o.\n", 8);
    printf("tf .%#15.4o.\n", 8);
    ft_printf("my .%#15.4x.\n", 8);
    printf("tf .%#15.4x.\n", 8);
    ft_printf("my .%#15.4X.\n", 8);
    printf("tf .%#15.4X.\n", 8);
    ft_printf("my .%15.4b.\n", 8);
    //printf(".%10.4s.\n", "loremipsum");
    //printf(".%10.2c.\n", 123);
    //printf(".%10.2c.\n", 123);
    /*
    ft_printf(".%5d.\n", 42);
    ft_printf(".%15.2s.\n", "lorem ipsum");
    printf("__________________\n\n");
    printf(".%15.2s.\n", "lorem ipsum");
    printf("__________________\n\n");
    ft_printf("01234%10.005s5678%05.15s9 ca vaut %5.15d\n", "test", "lorem ipsum", 42);
    printf("01234%10.005s5678%05.15s9 ca vaut %5.15d\n", "test", "lorem ipsum", 42);
    */
}