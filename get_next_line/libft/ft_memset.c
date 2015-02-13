/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:34:46 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:33:25 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*t;

	if (len)
	{
		t = (unsigned char *)b;
		while (len--)
			t[len] = (unsigned char)c;
	}
	return (b);
}
