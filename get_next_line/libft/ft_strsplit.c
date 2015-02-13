/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:43:52 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:04:03 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_sizew(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s++ != c)
		i++;
	return (i);
}

int		ft_words(char const *s, char c)
{
	int		i;
	int		beg;

	beg = 1;
	i = 0;
	while (*s)
	{
		if (*s != c && beg == 1)
		{
			i++;
			beg = 0;
		}
		if (*s == c && beg == 0)
			beg = 1;
		s++;
	}
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		i;
	int		t;
	int		i2;

	if (!(s))
		return (NULL);
	i2 = -1;
	i = ft_words(s, c);
	if (!(dst = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	dst[i] = '\0';
	while (++i2 < i)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (dst);
		t = ft_sizew(s, c);
		dst[i2] = ft_strnew(t);
		while (--t >= 0)
			dst[i2][t] = s[t];
		s += ft_sizew(s, c);
	}
	return (dst);
}
