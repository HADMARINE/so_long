/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:10:42 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/13 18:07:55 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	getlength(unsigned int n)
{
	unsigned int	len;

	len = 2;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*utoa(unsigned int n)
{
	char	*str;
	char	*sp;

	str = (char *)malloc(getlength(n) * sizeof(char));
	if (!str)
		return (NULL);
	sp = str + getlength(n) - 1;
	*sp-- = '\0';
	while (sp - str >= 0)
	{
		*sp-- = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
