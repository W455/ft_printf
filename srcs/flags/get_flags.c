/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:47:16 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/12 01:29:59 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static int     is_conv(char c)
{
    return ((c == 'S' || c == 's' || c == 'p' || c == 'd' || c == 'D'
|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'u'
|| c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 'e'
|| c == 'E' || c == 'g' || c == 'G' || c == 'a' || c == 'A'
|| c == 'n' || c == 'b' || c == '%') ? TRUE : FALSE);
}

static int     is_flag(char c)
{
    return ((c == 'l' || c == 'L' || c == 'j' || c == 'z'
|| c == 'h' || c == ' ' || c == '0' || c == '-' || c == '+'
|| c == '.' || c == '$' || c == '\'' || c == '*') ? TRUE : FALSE);
}

static	void	flag_conflic(t_flag *env)
{
	env->id == 'i' ? env->id = 'd' : 0;
	env->id == 'p' ? env->flag['#'] = 1 : 0;
	env->id == 'p' ? env->flag['L'] = 1 : 0;
	if (env->id != 'o' && env->id != 'X' && env->id != 'x'
			&& env->id != 'p' && env->id != 'b')
		env->flag['#'] = 0;
	if (env->precision >= 0 ||
			(env->id != 'o' && env->id != 'X' && env->id != 'x' &&
			env->id != 'u' && env->id != 'd' && env->id != 'i'))
		env->flag['0'] = 0;
	env->flag['-'] ? env->flag['0'] = 0 : 0;
	env->flag['+'] ? env->flag[' '] = 0 : 0;
	env->id != 'd' && env->id != 'i' ? env->flag[' '] = 0 : 0;
	env->id != 'd' && env->id != 'i' ? env->flag['+'] = 0 : 0;
}

void            get_flags(char *s, t_flag *env)
{
    while (*++s)
    {
        is_flag(*s) ? FLAG[*s] = 1 : 0;        
        *s == '0' && *(s - 1) == '.' ? FLAG['0'] = 0 : 1;
        is_conv(*s) ? ID = *s : 0;                
        if (is_conv(*s))  
            break ;
        else if (ft_isdigit(*s) && *s != '0' && *(s - 1) != '.')
        {
            WIDTH = 0;
            while (ft_isdigit(*s))
                WIDTH = WIDTH * 10 + *s++ - '0';
            s--;
        }
        else if ((ft_isdigit(*s) && *(s - 1) == '.'))
        {
            PRECISION = 0;
            while (ft_isdigit(*s))
                PRECISION = PRECISION * 10 + *s++ - '0';
            s--;
        }
    }
}