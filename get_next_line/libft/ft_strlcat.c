/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:03:34 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:42:52 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size1;
	size_t	i;
	size_t	size2;

	i = 0;
	size2 = ft_strlen(src);
	size1 = ft_strlen(dst);
	while (i < size)
	{
		if (i >= size1)
			dst[i] = src[i - size1];
		i++;
	}
	if (i > size1)
		dst[i - 1] = '\0';
	if (size >= size1)
		return (size1 + size2);
	return (size2 + size);
}
