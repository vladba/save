/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:50:48 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:32:33 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if (ptr_src <= ptr_dst)
	{
		ptr_dst += len - 1;
		ptr_src += len - 1;
		while (len > 0)
		{
			*ptr_dst-- = *ptr_src--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
