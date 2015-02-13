/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/07 09:11:04 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:40:19 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	if (!(dup = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = s1[i];
	return (dup);
}
