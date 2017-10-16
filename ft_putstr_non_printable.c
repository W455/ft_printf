/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:06:22 by oukrifa           #+#    #+#             */
/*   Updated: 2017/03/16 17:11:36 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

void					ft_putchar(char c);

static unsigned int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int				ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 31)
			return (FALSE);
		while (j < i)
			if (base[i] == base[j++])
				return (FALSE);
		j = 0;
		i++;
	}
	return (i >= 2 ? TRUE : FALSE);
}

static void				ft_putnbr_base(int n, char *base)
{
	unsigned int	nb;

	if (ft_check_base(base) == 0)
		return ;
	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb >= ft_len(base))
	{
		ft_putnbr_base(nb / ft_len(base), base);
		ft_putnbr_base(nb % ft_len(base), base);
	}
	else
		ft_putchar(base[nb]);
}

void					ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	if (str[i] == 0)
		return ;
	while (str[i])
	{
		if (str[i] <= 31 || str[i] == 127)
		{
			ft_putchar('\\');
			if (str[i] / 16 < 1)
				ft_putchar('0');
			ft_putnbr_base(str[i], "0123456789abcdef");
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
