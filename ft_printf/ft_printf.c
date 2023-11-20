/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:44:52 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/13 18:00:28 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parser(const char *str, va_list *valist);
int	counter(const char *str);

int	ft_printf(const char *str, ...)
{
	va_list	valist;
	int		len;

	va_start(valist, str);
	len = parser(str, &valist);
	va_end(valist);
	return (len);
}
