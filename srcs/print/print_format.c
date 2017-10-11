/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:00:41 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/12 01:21:13 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_print(t_flag *env, const char *format)
{
    void (*fun_ptr)(va_list *app, struct s_flag *flag);  

    env->i = 0;
    env->fd = 1;
    while (*format  && env->n_printed >= 0)
    {
        if (*format != '%' && *format)
            add_to_buff(env, *format++);
        else
        {
                if (env->init == 0)
                    init_flag(env);
                reset_flag(env);
                get_flags((char *)(format), env);              
                fun_ptr = env->cvt[ID];   
                if (env->cvt[ID])
                    fun_ptr(&env->ap, env);
               while (*format != ID && *format)
                    format++;
                format++;
        }
    }
    add_to_buff(env, *format);
}

void    add_to_buff(t_flag *env, char c)
{
    if (INDEX == BUFF_SIZE)
    {
        write(env->fd, BUFFER, BUFF_SIZE);
        INDEX = 0;
    }
    BUFF[INDEX++] = c;
    N_PRINT++;
    WIDTH--;
}