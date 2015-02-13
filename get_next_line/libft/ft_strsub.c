/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:54:20 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:04:48 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!(s) || ft_strlen(s) < start)
		return (NULL);
	if (!(dst = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst = ft_strncpy(dst, s + start, len);
	dst[len] = 0;
	return (dst);
}
