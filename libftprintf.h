/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:51:35 by oukrifa           #+#    #+#             */
/*   Updated: 2017/09/07 23:06:48 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define BUFF_SIZE 3477594 

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

#endif