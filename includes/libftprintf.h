/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:51:35 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/18 00:49:00 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <locale.h>
# include <wchar.h>
# include <inttypes.h>

#define BASE_MAJ    "0123456789ABCDEF"
#define BASE_MIN    "0123456789abcdef"

#define BINAIRE     2
#define OCTALE      8
#define HEXA        16

# define PRECISION      env->precision
# define N_PRINT        env->n_printed
# define WIDTH          env->width
# define BUFF           env->buff
# define FLAG           env->flag
# define ID             env->id
# define INDEX          env->i

# define BUFF_SIZE      55278

# define TRUE           1
# define FALSE          0

typedef union                   u_cast
{
    int				            d;
	unsigned int	            u;
	short			            h;
	signed char		            hh;
	char			            c;
	long int		            l;
	long long int	            ll;
	float			             f;
	intmax_t		            j;
	wint_t			            lc;
    char			            uni[4];
    unsigned int				ud;
	unsigned short				uh;
	unsigned char				uhh;
	unsigned long int			ul;
	unsigned long long int		ull;
	size_t			            z;
	uintmax_t					uj;
}                               t_cast;

typedef struct                  s_flag
{
    char                        flag[128];
    char                        buff[BUFF_SIZE];
    int                         a;
    int                         b;
    int                         i;
    int                         precision;
    int                         width;
    void                        *cvt[128];
    va_list                     ap;
    long long                   n_printed;
    int                         fd;
    int                         init;
    int                         id;
}                               t_flag;

char	            *ft_itoa_base(unsigned long long nb, int base, 
                    char *basef, char *buf, t_flag *env);
void	            ft_bzero(void *b, size_t len);
int		            ft_isdigit(int c);
size_t		        ft_strlen(const char *s);
void	            *ft_memchr(const void *str, int c, size_t n);
void	            *ft_memset(void *b, int c, size_t len);


                    

long long	        ft_printf_get_arg(va_list *ap, t_flag *env);


int                 get_flags(char *s, t_flag *env);
void			    reset_flag(t_flag *env);
void			    init_flag(t_flag *flag);

void                add_to_buff(t_flag *env, char c);


void                put_s(char *s, t_flag *env);
void	    		put_d(char *p, int len, t_flag *env, int s_len);
void                put_c(char c, t_flag *env);


int                 is_conv(char c);

void                conv_mod(va_list *ap, t_flag *env);
void                conv_lc(va_list *ap, t_flag *env);
void                conv_ls(va_list *ap, t_flag *env);
void                conv_s(va_list *ap, t_flag *env);
//void                conv_n(va_list *ap, t_flag *env);
void                conv_o(va_list *ap, t_flag *env);
void                conv_u(va_list *ap, t_flag *env);
void                conv_x(va_list *ap, t_flag *env);
void                conv_X(va_list *ap, t_flag *env);
void                conv_b(va_list *ap, t_flag *env);
//void                conv_e(va_list *ap, t_flag *env);
//void                conv_E(va_list *ap, t_flag *env);
void                conv_c(va_list *ap, t_flag *env);
//void                conv_g(va_list *ap, t_flag *env);
void	            conv_d(va_list *ap, t_flag *flag);


void	            format_print(t_flag *env, const char *fmt);



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

void			put_ls(wchar_t *p, int len, t_flag *flag);
void		    conv_ls(va_list *app, t_flag *flag);
void	        conv_lc(va_list *app, t_flag *flag);



#endif