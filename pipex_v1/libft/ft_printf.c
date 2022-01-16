/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:58:22 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/11 12:39:26 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* !!! DISCLAIMER :                                                           */
/*                                                                            */
/* As not intended, this ft_printf does not implement :                       */
/*                                                                            */
/* 1. correspondance between number of arguments and number of conversions    */
/*    specified in the placeholder by the '%'                                 */
/*                                                                            */
/* 2. check and conversion between data types from arguments                  */
/* 	  so the user is responsible to provide appropriates data type arguments  */
/* ************************************************************************** */

#include "libft.h"

static int	count_conversions(const char *s, int c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			if (*(s + 1) == 'c' || *(s + 1) == 's' || *(s + 1) == 'd'
				|| *(s + 1) == 'i' || *(s + 1) == 'u' || *(s + 1) == 'p'
				|| *(s + 1) == 'x' || *(s + 1) == 'X' || *(s + 1) == '%')
			{
				count++;
				s++;
			}
			else
				return (-1);
		}
		s++;
	}
	return (count);
}

static int	check_specifiers(const char *placeholder)
{
	int	tot_args;

	tot_args = count_conversions(placeholder, '%');
	if (tot_args < 0)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(DEFAULT, 2);
		ft_putstr_fd("incompatible format specifier.\n", 2);
		ft_putstr_fd("Expected specifier after '%' :\n", 2);
		ft_putstr_fd(GREEN"c"DEFAULT" -> char | ", 2);
		ft_putstr_fd(GREEN"s"DEFAULT" -> string | ", 2);
		ft_putstr_fd(GREEN"d/i"DEFAULT" -> integer | ", 2);
		ft_putstr_fd(GREEN"u"DEFAULT" -> integer(+) | ", 2);
		ft_putstr_fd(GREEN"p"DEFAULT" -> pointer | ", 2);
		ft_putstr_fd(GREEN"x/X"DEFAULT" -> hexadecimal | ", 2);
		ft_putstr_fd(GREEN"%"DEFAULT" -> '%'\n", 2);
		return (-1);
	}
	if (tot_args == 0)
		ft_putstr_fd((char *)placeholder, 1);
	return (tot_args);
}

static int	print_arg(va_list args, const char *placeholder)
{
	int	count;

	count = 0;
	if (*(placeholder + 1) == 'c')
		count += print_char(va_arg(args, int));
	if (*(placeholder + 1) == 's')
		count += print_str(va_arg(args, char *));
	if (*(placeholder + 1) == 'p')
		count += print_ptr(va_arg(args, void *));
	if (*(placeholder + 1) == 'd' || *(placeholder + 1) == 'i')
		count += print_int(va_arg(args, int));
	if (*(placeholder + 1) == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	if (*(placeholder + 1) == 'x' || *(placeholder + 1) == 'X')
		count += print_hexa(va_arg(args, unsigned int), *(placeholder + 1));
	if (*(placeholder + 1) == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *placeholder, ...)
{
	va_list	args;
	int		check_args;
	int		i;
	int		count;

	va_start(args, placeholder);
	check_args = check_specifiers(placeholder);
	if (check_args < 0)
		return (-1);
	if (check_args == 0)
		return (ft_strlen(placeholder));
	i = -1;
	count = 0;
	while (placeholder[++i])
	{
		if (placeholder[i] == '%')
			count += print_arg(args, &placeholder[i++]);
		else
			count += print_char(placeholder[i]);
	}
	va_end(args);
	return (count);
}
