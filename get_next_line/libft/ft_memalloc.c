/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:25:36 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 14:44:23 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*src;
	char	*str;

	if (!(src = (void*)malloc(sizeof(char) * size)))
		return (NULL);
	str = (char*)src;
	while (size--)
		str[size] = 0;
	return (src);
}
