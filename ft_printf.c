/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:03:02 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/09 22:02:56 by oukrifa          ###   ########.fr       */
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
        static t_flag env;
    
        env.n_printed = 0;
        va_start(env.ap, format);
        format_print(&env, format);
        va_end(env.ap);
        return (env.n_printed);
}

void	format_print(t_flag *env, const char *format)
{
    void (*fun_ptr)(va_list *app, struct s_flag *flag);  

    env->i = 0;
    env->fd = 1;//stream->_file;
    while (*format && env->n_printed >= 0)
    {
        if (*format != '%' && *format)
            add_to_buff(env, *format++);
        else
        {
                if (env->init == 0)
                    init_flag(env);
                reset_flag(env);
                get_flags((char *)(format), env);              
                fun_ptr = env->cvt[env->id];   
                if (env->cvt[env->id])
                    fun_ptr(&env->ap, env);
               while (*format != env->id && *format)
                    format++;
                format++;
        }
    }
    add_to_buff(env, *format);
      //  printf("\nn printed = %lld\nbuf = %s\n", env->n_printed, env->buff);                
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
    void (*fun_ptr)(va_list *app, struct s_flag *flag);  
    static t_flag env;
    char *format = (char *)fmt;

    env.i = 0;
    env.n_printed = 0;
   // env.ap = &ap;
    env.fd = stream->_file;
    while (*format && env.n_printed >= 0)
    {
        if (*format != '%')
            add_to_buff(&env, *format++);
        else
        {
             //   if (env.init == 0)
               //     init_flag(&env);
                reset_flag(&env);
                get_flags(format, &env);              
              //  fun_ptr = env.cvt[env.id];   
                conv_s(&ap, &env);
             //   fun_ptr((env.ap), &env);
            
                while (*format != 's' && *format)
                    format++;
           //     format++;
              //  fun_ptr = env.cvt[env.id];
               // if (env.cvt[env.id])
                //    fun_ptr((env.ap), &env);
               // else
                 //   format--;
        }
        }
    write(env.fd, env.buff, env.i);
    va_end(ap);
    return (env.n_printed);
}

int main(void)
{
    int i = 1;
    while (i < 10)
    {
        ft_printf("\n01234%10.005s5678%05.15s9", "test", "lorem ipsum");
     printf("\n01234%10.005s5678%05.15s9", "test", "lorem ipsum");
       ft_fprintf("\n %d", i);
    i++;
    }
}