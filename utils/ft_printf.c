/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:22:51 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/02 12:22:51 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putchar(char c)
{
	int	cnt;

	cnt = 0;
	cnt += write(1, &c, 1);
	return (cnt);
}

int	ft_putnbr(int n)
{
	unsigned int	i;
	int				cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt += ft_putchar('-');
		i = -n;
	}
	else
		i = n;
	if (i > 9)
	{
		cnt += ft_putnbr(i / 10);
		cnt += ft_putchar((i % 10) + '0');
	}
	else
		cnt += ft_putchar(i + '0');
	return (cnt);
}

int	ft_putstr(char *s)
{
	int	idx;
	int	cnt;

	cnt = 0;
	idx = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[idx] != '\0')
	{
		cnt += write(1, &s[idx], 1);
		idx++;
	}
	return (cnt);
}

int	type_srch(va_list vag, char str, int a)
{
	if (str == '%')
		a = write(1, "%", 1);
	else if (str == 'c')
		a = ft_putchar(va_arg(vag, int));
	else if (str == 's')
		a = ft_putstr(va_arg(vag, char *));
	else if (str == 'd')
		a = ft_putnbr(va_arg(vag, int));
	else
		str++;
	return (a);
}

int	ft_printf(const	char *s, ...)
{
	int		a;
	va_list	vag;

	a = 0;
	va_start(vag, s);
	while (*s)
	{
		if (*s == '%')
			a += type_srch(vag, *(++s), a);
		else
			a += ft_putchar(*s);
		s++;
	}
	va_end(vag);
	return (a);
}
