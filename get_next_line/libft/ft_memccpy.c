/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:25:54 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 14:44:44 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*p;
	const char	*p2;

	i = 0;
	p = (char*)dst;
	p2 = (const char*)src;
	while (i < n && (i == 0 || p2[i - 1] != c))
	{
		p[i] = p2[i];
		i++;
	}
	if (i > 0 && p2[i - 1] == c)
		return (p + i);
	return (NULL);
}
