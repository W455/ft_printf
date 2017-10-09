/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 19:39:13 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/05 23:37:16 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	size_int_base(int n, unsigned int base)
{
	unsigned int size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while(n / 10 > 0)
	{
		size++;
		n = n / base;
	}
	return(size);
}

unsigned int	size_unint_base(unsigned int n, unsigned int base)
{
	unsigned int size;

	size = 1;
	while(n /10 >= 0)
	{
		size++;
		n = n / base;
	}
	return(size);
}

void	conv_int(t_flag *env, int n, unsigned int size, unsigned int base)
{
	int j;

	j = 0;
	if (n < 0)
	{
		add_to_buff(env, '-');
		n = -n;
	}
	while (n > 0 || size > 0)
	{
		add_to_buff(env, n / (base x ft_power(size)));
	}
	env->i += j; 
}

void	conv_unint(t_flag *env, unsigned int n, unsigned int size, unsigned int base)
{
	int j;

	j = 0;
	while (n > 0 || size > 0)
	{
		add_to_buff(env, n / (base x ft_power(size)));
	}
	env->i += j; 
}

/*
unsigned int	size_int(int n)
{
	unsigned int size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while(n / 10 > 0)
	{
		size++;
		n = n / 10;
	}
	return(size);
}

unsigned int	size_uint(unsigned int n)
{
	unsigned int size;

	size = 1;
	while (n / 10 > 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

unsigned int	size_hexa(unsigned int n)
{
	unsigned int size;

	size = 1;
	while (n / 16 > 0)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

unsigned int	size_octal(unsigned int n)
{
	unsigned int size;

	size = 1;
	while (n / 8)
	{
		size++;
		n = n / 8;
	}
	return (size);
}

unsigned int	size_binaire(unsigned int n)
{
	unsigned int size;

	size = 1;
	while (n / 2)
	{
		size++;
		n = n / 2;
	}
	return (size);
}
void	conv_int(t_flag *env, int n, unsigned int size)
{
	int j;

	j = 0;
	while (n > 0 || size > 0)
	{
		add_to_buff(env, n / (10  x ft_power(size)));
		size--;
	}
	env->i += j;
}

void	conv_uint(t_flag *env, unsigned int n, unsigned int size)
{
	int j;

	j = 0;
	while (n > 0 || size > 0)
	{
		add_to_buff(env, n / (10  x ft_power(size)));
		size--;
	}
	env->i += j;
}

void	conv_uninthexa(t_flag *env, int n, unsigned int size)
{
	int j;

	j = 0;
	while (n > 0 || size > 0)
	{
		add_to_buff(env, n / (16  x ft_power(size)));
		size--;
	}
	env->i += j;
}

void	conv_uintoctal(t_flag *env, int n, unsigned int size)
{
	int j;

	j = 0;
	while (n > 0 || size > 0)
	{
		add_to_buff(env, n / (8  x ft_power(size)));
		size--;
	}
	env->i += j;
}

void	conv_uinbinaire(t_flag *env, int n, unsigned int size)
{
	int j;

	j = 0;
	while (n > 0 || size > 0)
	{
		add_to_buff(env, n / (2  x ft_power(size)));
		size--;
	}
	env->i += j;
}*/