/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:47:16 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/18 22:08:52 by oukrifa          ###   ########.fr       */
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

int            get_flags(char *s, t_flag *env)
{
    char *start = s;
    while (*++s)
    {   
        //if (is_flag(*s))
       // {
            FLAG[*s] = is_flag(*s) ? 1 : 0; 
            *s == '0' && *(s - 1) == '.' ? FLAG['0'] = 0 : 1;
        //if(*s == '0')
          //  FLAG['0'] = 1;
       //s printf("flag[0] = %d et width = %d.\n", FLAG['0'], WIDTH);    
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