/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:54:48 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/09 18:17:50 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	unsigned int	count;

	count = 0;
	if (!s)
		return (print_str("(null)"));
	while (*s)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}
