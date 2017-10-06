/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:47:16 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/06 20:25:51 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57) ? 1 : 0);
}

typedef enum {False = 0, True = 1} bool;

bool is_conv(char c)
{
    bool i;

    if (c == 'S' || c == 's' || c == 'p' || c == 'd' || c == 'D'
|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'u'
|| c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 'e'
|| c == 'E' || c == 'g' || c == 'G' || c == 'a' || c == 'A'
|| c == 'n' || c == 'b' || c == '%')
    i = True;
    else
        i = False;
    return (i);
}

bool is_flag(char c)
{
    if (c == 'l' || c == 'L' || c == 'j' || c == 'z'
|| c == 'h' || c == ' ' || c == '0' || c == '-' || c == '+'
|| c == '.' || c == '$' || c == '\'' || c == '*')
        return(True);
    return (False);
}

int get_flags(char * s, t_flag *env)
{
    char *p = s;

    while (*++s)
    {
        is_flag(*s) ? env->flag[*s] = 1 : 0;
        is_conv(*s) ? env->id = *s : 0;                
        if (is_conv(*s))  
            break ;
        else if (ft_isdigit(*s) && *s != '0' && *(s - 1) != '.')
        {
            env->width = 0;
            while (ft_isdigit(*s))
                env->width = env->width * 10 + *s++ - '0';
            s--;
        }
        else if (ft_isdigit(*s) && *(s - 1) == '.')
        {
            while (ft_isdigit(*s))
                env->precision = env->precision * 10 + *s++ - '0';
            s--;
        }
    }
    return (s - p);
}

void    add_to_buff(t_flag *env, char c)
{
    if (INDEX == BUFF_SIZE)
    {
        write(env->fd, BUFFER, BUFF_SIZE);
        INDEX = 0;
    }
    BUFFER[INDEX++] = c;
    N_PRINT++;
    env->width--;
}

/*
void    conv_d(t_flag *env, int n)
{
    int i = 0;

    while (n > 0)
    {
        add_to_buff(env, n / 10 * ft_power());
        n /= 10;
    }
}
*/

int main(void)
{
    static t_flag env;
    char *s = "10->|%10.5s|\n";
    char *st = "123456789";
    
    int i = -1;
    env.precision = 0;
    
    while (*s)
    {
        if (*s == '%')
        {
            s += get_flags(s, &env);
           // printf(" avant : %d\n", env.precision);
            conv_s(st, &env);
        }
        else
            write(1, s, 1);
        s++;
    }
    i = -1;
    while (++i < 128)
        if (env.flag[i])
            printf("'%c' = %d \n", i, env.flag[i]);
    printf("width = %d\n", env.width);
    printf("precision = %d\n", env.precision);
}