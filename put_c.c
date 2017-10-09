
#include "libftprintf.h"

static void     put_space(int pos, t_flag *env)
{
    if (pos == 1)
    {
        while (!env->flag('-') && !env->flag['0']) && 
                env->width > env->precision)
                add_to_buff(env, ' ');
        env->flag('-') ? 1 : env->precision++;
    }    
    if (pos == 2)
        while (env->flag['-'] && env->width >= 0)
            add_to_buff(env, ' ');
}

static void     put_value(t_flag *env, char c)
{
    while (env->width > 0)
    {
        add_to_buff(env, ' ');
        env->width--;
    }
    add_to_buff(env, c);
}

void    put_c(char c, t_flag env)
{
    put_space(1, env);
    put_value(env, c);
    put_space(2, env);

}   