/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:57:15 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 14:43:32 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizen(int n, int i)
{
	while (n)
	{
		n /= 10;
		if (n)
			i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		zero;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	zero = 1;
	i = 1;
	i = (n < 0 ? i + 1 : i);
	i = ft_sizen(n, i);
	str = ft_strnew(i);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n || zero == 1)
	{
		zero = 0;
		str[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}
