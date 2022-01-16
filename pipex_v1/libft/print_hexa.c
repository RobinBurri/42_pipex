/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:56:18 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/09 18:17:52 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*buf_init(char *buf, unsigned long int nbr, int *size)
{
	nbr /= 16;
	while (nbr)
	{
		nbr /= 16;
		*size += 1;
	}
	buf = malloc(*size * sizeof(char));
	if (!buf)
		return (0);
	buf[*size] = 0;
	*size -= 1;
	return (buf);
}

int	print_ptr(void *ptr)
{
	unsigned long int	nbr;
	char				*buf;
	int					size;

	if (!ptr)
		return (print_str("0x0"));
	nbr = (unsigned long int)ptr;
	buf = NULL;
	size = 3;
	buf = buf_init(buf, nbr, &size);
	if (!buf)
		return (print_str("0x0"));
	while (nbr)
	{
		buf[size--] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	buf[1] = 'x';
	buf[0] = '0';
	size = print_str(buf);
	free(buf);
	return (size);
}

int	print_hexa(unsigned long int nbr, int c_case)
{
	char				*buf;
	char				*set;
	int					size;

	if (!nbr)
		return (print_char('0'));
	if (c_case == 'x')
		set = "0123456789abcdef";
	else if (c_case == 'X')
		set = "0123456789ABCDEF";
	buf = NULL;
	size = 1;
	buf = buf_init(buf, nbr, &size);
	if (!buf)
		return (print_char('0'));
	while (nbr)
	{
		buf[size--] = set[nbr % 16];
		nbr /= 16;
	}
	size = print_str(buf);
	free(buf);
	return (size);
}
