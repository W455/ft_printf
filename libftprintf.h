/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:51:35 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/09 21:55:58 by oukrifa          ###   ########.fr       */
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
    int             init;
    int             id;
}                   t_flag;

void			init_flag(t_flag *flag);
void			reset_flag(t_flag *env);

void    add_to_buff(t_flag *env, char c);
void    put_s(char *s, t_flag *env);
void    conv_s(va_list *ap, t_flag *env);

void    get_flags(char *s, t_flag *env);

void	format_print(t_flag *env, const char *fmt);


int ft_printf(const char *format, ...);
int ft_fprintf(FILE *stream, const char *format, ...);
int ft_sprintf(char *str, const char *format, ...);
int ft_snprintf(char *str, size_t size, const char *format, ...);
int ft_vprintf(const char *format, va_list ap);
int ft_vfprintf(FILE *stream, const char *format, va_list ap);
int ft_vsprintf(char *str, const char *format, va_list ap); 
int ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);


#endif