#include "libftprintf.h"

static	void	ft_put_space(int call, int s_len, int len, t_flag *flag)
{
	if (call == 1)
	{
		while (!flag->flag['-'] && !flag->flag['0'] && flag->width >
				(flag->precision > len ? flag->precision : len) + s_len)
			add_to_buff(flag, ' ');
	}
	else if (call == 2)
	{
		while (flag->flag['-'] && flag->width > 0)
			add_to_buff(flag, ' ');
	}
}

long long	get_unsigned(va_list *ap, t_flag *flag)
{
	if (flag->flag['z'])
		return (va_arg(*ap, size_t));
	if (flag->flag['j'])
		return (va_arg(*ap, uintmax_t));
	if (flag->flag['L'])
		return (va_arg(*ap, unsigned long long));
	if (flag->flag['l'])
	{
		return (flag->id == 'c' ? va_arg(*ap, wchar_t)
				: va_arg(*ap, unsigned long));
	}
	if (flag->flag['h'])
		return ((unsigned short)va_arg(*ap, unsigned int) & 4294967295);
	if (flag->flag['H'])
		return ((unsigned char)va_arg(*ap, unsigned int) & 4294967295);
	return (va_arg(*ap, unsigned int) & 4294967295);
}

long long	ft_printf_get_arg(va_list *ap, t_flag *flag)
{
	if (flag->id == 'o' || flag->id == 'x' || flag->id == 'X' ||
			flag->id == 'u')
		return (get_unsigned(ap, flag));
	else
	{
		if (flag->flag['z'])
			return (va_arg(*ap, size_t));
		if (flag->flag['j'])
			return (va_arg(*ap, intmax_t));
		if (flag->flag['L'])
			return (va_arg(*ap, long long));
		if (flag->flag['l'])
			return (va_arg(*ap, long));
		if (flag->flag['h'])
			return ((short)va_arg(*ap, int) & 4294967295);
		if (flag->flag['H'])
			return ((signed char)va_arg(*ap, int) & 4294967295);
	}
	return (va_arg(*ap, int) & 4294967295);
}
static	void	ft_put_sign(t_flag *flag, int s_len)
{
	if (flag->flag['#'] && s_len)
	{
		add_to_buff(flag, '0');
		flag->id == 'x' || flag->id == 'p' ? add_to_buff(flag, 'x') : 0;
		flag->id == 'X' ? add_to_buff(flag, 'X') : 0;
		flag->id == 'b' ? add_to_buff(flag, 'b') : 0;
		flag->precision >= 0 && flag->id == 'o' ?
			(flag->precision -= s_len) : 0;
	}
	else
	{
		flag->flag[' '] ? add_to_buff(flag, ' ') : 0;
		flag->flag['+'] == 1 ? add_to_buff(flag, '+') : 0;
		flag->flag['+'] == 2 ? add_to_buff(flag, '-') : 0;
	}
}

static	void	ft_put_precision_or_0(t_flag *flag, int len)
{
	if (flag->precision == -1 && flag->flag['0'])
		flag->precision = flag->width;
	while (flag->precision-- > len)
		add_to_buff(flag, '0');
}

static	void	ft_put_value(t_flag *flag, char *p)
{
	if (flag->id == 'c')
		add_to_buff(flag, *p++);
	while (*p)
		add_to_buff(flag, *p++);
}

void			ft_printf_putd(char *p, int len, t_flag *flag, int s_len)
{
	flag->width ? ft_put_space(1, s_len, len, flag) : 0;
	s_len ? ft_put_sign(flag, s_len) : 0;
	ft_put_precision_or_0(flag, len);
	ft_put_value(flag, p);
	flag->width > 0 ? ft_put_space(2, s_len, len, flag) : 0;
}

static	char	*cvt_d1(unsigned long long nbr, char *buf)
{
	char	*p;

	p = buf + 44;
	*p = 0;
	if (nbr == 0)
		*--p = '0';
	while (nbr)
	{
		*--p = nbr % 10 + '0';
		nbr /= 10;
	}
	return (p);
}

void			conv_d(va_list *app, t_flag *flag)
{
	long long		nbr;
	char			buf[44];
	char			*p;
	int				s_len;

	s_len = 0;
	nbr = 0;
	nbr = ft_printf_get_arg(app, flag);
	nbr = (flag->flag['l'] || flag->flag['L'] || flag->flag['z'] ||
			flag->flag['j']) ? nbr : (int)nbr;
	p = cvt_d1(nbr > 0 ? nbr : -nbr, buf);
	if (nbr <= 4294967295 && !(flag->flag['l'] || flag->flag['L'] ||
				flag->flag['z'] || flag->flag['j']))
	{
		(int)nbr < 0 ? flag->flag['+'] = 2 : 0;
		(int)nbr < 0 ? flag->flag[' '] = 0 : 0;
	}
	else
	{
		nbr < 0 ? flag->flag['+'] = 2 : 0;
		nbr < 0 ? flag->flag[' '] = 0 : 0;
	}
	flag->flag['+'] || flag->flag[' '] ? s_len = 1 : 0;
	flag->precision == 0 && *p == '0' ? p = (buf + sizeof(buf)) : 0;
	ft_printf_putd(p, (buf + sizeof(buf)) - p, flag, s_len);
}
