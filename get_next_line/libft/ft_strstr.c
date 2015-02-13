/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 14:27:47 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:47:30 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		imil;
	int		i;
	int		index;
	int		diff;

	i = -1;
	if (!(*s2))
		return ((char *)s1);
	while (s1[++i])
	{
		diff = 0;
		if (s1[i] == s2[0])
		{
			index = i;
			imil = -1;
			diff = 1;
			while (s2[++imil])
				if (s1[imil + index] != s2[imil])
					diff = 0;
		}
		if (diff == 1)
			return ((char *)(s1 + index));
	}
	return (NULL);
}
