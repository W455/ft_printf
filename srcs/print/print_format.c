/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:00:41 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/20 20:27:10 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_print(t_flag *flag, const char *fmt)
{
	void (*fun_ptr)(va_list *app, struct s_flag *flag);

    flag->i = 0;    
	while (*fmt && flag->n_printed >= 0)
	{
		if (*fmt != '%' || *(fmt + 1) == '%')
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
}

void    add_to_buff(t_flag *env, char c)
{
    if (INDEX == BUFF_SIZE)
    {
        write(env->fd, BUFF, BUFF_SIZE);
        INDEX = 0;
    }
    BUFF[INDEX++] = c;
    N_PRINT++;
    WIDTH--;
}