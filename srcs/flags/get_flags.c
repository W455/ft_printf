/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:47:16 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/20 20:28:00 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int     is_conv(char c)
{
    return (ft_memchr("SspdDioOuUxXcCeEgGaAnb%", c, 23) ? TRUE : FALSE);
}

static int     is_flag(char c)
{
    return (ft_memchr("lLjzh 0-+=#.,$'*", c, 16) ? TRUE : FALSE);
}

static	void	flag_conflict(t_flag *env)
{
	env->id == 'i' ? env->id = 'd' : 0;
	env->id == 'D' ? env->id = 'd' : 0;
	env->id == 'U' ? env->id = 'u' : 0;
	env->id == 'O' ? env->id = 'o' : 0;
	env->id == 'p' ? env->flag['#'] = 1 : 0;
	env->id == 'p' ? env->flag['L'] = 1 : 0;
	env->id == 'p' ? env->id = 'x' : 0;
    env->id == 'S' ? env->flag['l'] = 1 : 0;
	env->id == 'S' ? env->id = 's' : 0;
    env->id == 'C' ? env->flag['l'] = 1 : 0;
	env->id == 'C' ? env->id = 'c' : 0;
	if (env->id != 'o' && env->id != 'X' && env->id != 'x'
			&& env->id != 'p' && env->id != 'b')
		env->flag['#'] = 0;
    if ((PRECISION >= 0 && (ID == 'd')) || 
    (env->id != 'o' && env->id != 'X' && env->id != 'x' &&
			env->id != 'u' && env->id != 'd' && env->id != 'i'))
		env->flag['0'] = 0;
	env->flag['-'] ? env->flag['0'] = 0 : 0;
	env->flag['+'] ? env->flag[' '] = 0 : 0;
	env->id != 'd' && env->id != 'i' ? env->flag[' '] = 0 : 0;
	env->id != 'd' && env->id != 'i' ? env->flag['+'] = 0 : 0;
}

static	void	maj_or_lmin(char fmt, t_flag *flag)
{
	fmt <= 'Z' && fmt >= 'A' && fmt != 'X' ? flag->flag['l'] += 2 : 0;
	fmt == 'c' && flag->flag['l'] == 1 ? (fmt = 'C') : 0;
	fmt == 's' && flag->flag['l'] == 1 ? (fmt = 'S') : 0;
	flag->flag['l'] > 1 ? flag->flag['L'] = 1 : 0;
	flag->flag['l'] > 1 ? flag->flag['l'] = 0 : 0;
	fmt = fmt <= 'Z' && fmt >= 'A' && fmt != 'X' && fmt != 'C' &&
		fmt != 'S' ? fmt + ('a' - 'A') : fmt;
	flag->cvt[(int)fmt] ? (flag->id = fmt) : 0;
}

void			get_flags(t_flag *flag, const char **fmt)
{
    while (!is_conv(**fmt) && is_flag((int)**fmt))
	{
        if ((flag->flag[(int)**fmt] == 1) && (**fmt == 'l' || **fmt == 'h'))
		{
            flag->flag[(int)**fmt - ('a' - 'A')] = 1;
			flag->flag[(int)**fmt] = 0;
		}
		else
        flag->flag[(int)**fmt] = 1;
		if (**fmt == '.' || ft_isdigit(**fmt))
		{
            **fmt == '.' ? (flag->precision = ft_atoi(*fmt + 1)) :
            (flag->width = ft_atoi(*fmt));
			while (ft_isdigit(*(*fmt + 1)))
            (*fmt)++;
		}
		(*fmt)++;
	}
	maj_or_lmin(**fmt, flag);
	(*fmt)++;
	flag_conflict(flag);
}
/*
void			get_flags(t_flag *env, const char **fmt)
{
    while (!is_conv(**fmt))// && is_flag((int)**fmt))
    {
		if ((FLAG[**fmt] == 1) && (**fmt == 'l' || **fmt == 'h'))
		{
			FLAG[**fmt - ('a' - 'A')] = 1;
			FLAG[**fmt] = 0;
		}
		else
			FLAG[**fmt] = 1;
		if (**fmt == '.' || ft_isdigit(**fmt))
		{
			**fmt == '.' ? (PRECISION = ft_atoi((char *)*fmt + 1)) :
				(WIDTH = ft_atoi((char *)*fmt));
			while (ft_isdigit(*(*fmt + 1)))
				(*fmt)++;
		}
        (*fmt)++;
	}
	maj_or_lmin(**fmt, env);
	(*fmt)++;
	flag_conflict(env);
}

int            get_flags(t_flag *env, const char *s)
{
    char *start = s;
    while (*++s)
    {   
        FLAG[*s] = is_flag(*s) ? 1 : 0; 
        *s == '0' && *(s - 1) == '.' ? FLAG['0'] = 0 : 1;
        if (is_conv(*s))  
        {
            is_conv(*s) ? ID = *s : 0;                      
            break ;
        }
        else if (ft_isdigit(*s) && *s != '0' && *(s - 1) != '.')
        {
            WIDTH = 0;
            while (ft_isdigit(*s))
            WIDTH = WIDTH * 10 + *s++ - '0';
            s--;          
        }
        else if (*s == '.')
        {
            s++;
            PRECISION = 0;
            while (ft_isdigit(*s))
            PRECISION = PRECISION * 10 + *s++ - '0';
            s--;
        }     
    }
    flag_conflict(env);
    return (s - start + 1);
}
*/