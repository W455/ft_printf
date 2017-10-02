/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 19:47:14 by oukrifa           #+#    #+#             */
/*   Updated: 2017/09/07 23:30:49 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#include <stddef.h>

int test(int val0, va_list ap);


int		infadd(int val0, ...)
{
	va_list ap;

	int nb_vals = 0;
	int res = 0;

	va_start(ap, val0);
    int i = val0;
    nb_vals = val0;
/*
	while (i--)
	{
		nb_vals++;
		val0 = va_arg(ap, int);
		res += val0;
		printf("%d\n", val0);
    }





	   if (val0)
	   {
	   printf("ERROR");
	   return (0);
       }
*/
    res = test(val0, ap);
	va_end(ap);
	printf("Il y a %d valeurs. La somme des arguments est %d.\n", nb_vals, res);
	return (res);



}

int test(int val0, va_list ap)
{
    int i = 0;
    int res=0;
    while (val0--)
	{
		i = va_arg(ap, int);
		res += i;
		printf("%d\n", val0);
    }
    va_end(ap);
    return (res);
}

int main(void)
{
	infadd(2, 1, 4); //, 1, 2, 3, 4, 5, 6, 7, 8);
	//	infadd();
	int a = 42;
	printf(" 1->%");//, printf("%u", -42, 24, 12));
	printf(" 2->4567 |%-10]5d| plip\n", 1);
	printf(" 3->4567 |%10]5d| plip\n", 12);
	printf(" 4->|%010.3d|\n", -12);
	printf(" 5->|%*d|\n", -2.5, 4);
	printf(" 6->|%010d|\n", -12); 
	printf(" 7->|%-5.5f|\n", -1.23456789);
	printf(" 8->|%0-10.5d|\n", -12);
	printf(" 8->|%-010.5d|\n", -12);
	printf(" 8->|%-10.5d|\n", -123456);
	printf(" 9->|%-10.5s|\n", "abcdefghijklmnopqrstxyz");
	printf("10->|%-010.5s|\n", "abcdefghijklmnopqrstxyz");
	printf("11->|%12s|\n", "bonjour");
	printf("12->%% lol\n");
	double x = 123456.;
	wchar_t c = L'ę';
	long n = 1000000;
	printf("n = %llhhhlO\n", 9);
}