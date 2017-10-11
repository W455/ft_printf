/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:51:35 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/12 01:03:47 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define N_PRINT        env->n_printed
# define BUFFER         env->buff
# define INDEX          env->i

# define BUFF_SIZE      55278

# define TRUE           1
# define FALSE          -1

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

void                get_flags(char *s, t_flag *env);
void			    reset_flag(t_flag *env);
void			    init_flag(t_flag *flag);

void                add_to_buff(t_flag *env, char c);


void                put_s(char *s, t_flag *env);

void                conv_mod(va_list *ap, t_flag *env);
void                conv_lc(va_list *ap, t_flag *env);
void                conv_ls(va_list *ap, t_flag *env);
void                conv_s(va_list *ap, t_flag *env);
void                conv_n(va_list *ap, t_flag *env);
void                conv_o(va_list *ap, t_flag *env);
void                conv_u(va_list *ap, t_flag *env);
void                conv_x(va_list *ap, t_flag *env);
void                conv_b(va_list *ap, t_flag *env);
void                conv_e(va_list *ap, t_flag *env);
void                conv_E(va_list *ap, t_flag *env);
void                conv_c(va_list *ap, t_flag *env);
void                conv_g(va_list *ap, t_flag *env);
void	            conv_d(va_list *ap, t_flag *flag);


void	            format_print(t_flag *env, const char *fmt)



int                 ft_printf(const char *format, ...);
// printf de base 
int                 ft_fprintf(FILE *stream, const char *format, ...);
// printf ou on choisit la sortie
int                 ft_sprintf(char *str, const char *format, ...);
// printf dans un buffer str[]
int                 ft_snprintf(char *str, size_t size, const char *format, ...);
// printf dans un buffer str[] ou on ecrit sur max size - 1. finir par \0

//envoie dune va lsit ou lieu des ...
int                 ft_vprintf(const char *format, va_list ap);
int                 ft_vfprintf(FILE *stream, const char *format, va_list ap);
int                 ft_vsprintf(char *str, const char *format, va_list ap); 
int                 ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);
#endif