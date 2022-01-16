/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:54:44 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/11 12:39:36 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(long int n)
{
	long int		nbr;
	unsigned int	count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += print_char('-');
		nbr *= -1;
	}
	if (nbr > 9)
		count += print_int(nbr / 10);
	count += print_char(nbr % 10 + '0');
	return (count);
}

int	print_unsigned(unsigned int n)
{
	unsigned int	nbr;
	unsigned int	count;

	nbr = n;
	count = 0;
	if (nbr > 9)
		count += print_unsigned(nbr / 10);
	count += print_char(nbr % 10 + '0');
	return (count);
}
