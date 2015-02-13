/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 14:27:47 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:11:19 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		imil;
	int		i;
	size_t	index;
	int		diff;

	i = -1;
	if (!(*s2))
		return ((char *)s1);
	if (n >= ft_strlen(s2))
		while (s1[++i] && ft_strlen(s2) + i <= ft_strlen(s1))
		{
			diff = 0;
			if (s1[i] == s2[0])
			{
				index = i;
				imil = -1;
				diff = 1;
				while (s2[++imil])
					if (s1[imil + index] != s2[imil] || index + imil >= n)
						diff = 0;
			}
			if (diff == 1)
				return ((char *)(s1 + index));
		}
	return (NULL);
}
