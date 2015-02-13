/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:53:18 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:05:08 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_end(const char *s)
{
	while (*s == '\n' || *s == '\t' || *s == ' ')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	char	*dst;

	if (!(s))
		return (NULL);
	i = 0;
	end = 0;
	while (*s == '\n' || *s == '\t' || *s == ' ')
		s++;
	while (s[i] && end != 1)
	{
		if (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
			end = ft_end(s + i);
		if (end != 1)
			i++;
	}
	if (!(dst = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	dst = ft_strncpy(dst, s, i);
	dst[i] = '\0';
	return (dst);
}
