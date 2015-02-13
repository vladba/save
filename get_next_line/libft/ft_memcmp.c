/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:05:17 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 14:45:39 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*p2;

	i = 0;
	if (n == 0)
		return (0);
	p = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (i < n && p[i] == p2[i] && p[i])
		i++;
	if (i == n)
		return (0);
	return (p[i] - p2[i]);
}
