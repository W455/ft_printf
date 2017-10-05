/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:51:35 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/05 23:50:05 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define BUFF_SIZE 1 
# define INDEX env->i
# define BUFFER env->buff
# define N_PRINT env->n_printed

typedef struct      s_flag
{
    char            flag[128];
    char            buff[BUFF_SIZE];
    int             i;
    int             precision;
    int             width;
    void            *cvt[128];
    va_list         ap;
    long long       n_printed;
    int             fd;
}                   t_flag;

void    add_to_buff(t_flag *env, char c);
void    conv_s(/*va_list *ap*/char *s, t_flag *env);


#endif