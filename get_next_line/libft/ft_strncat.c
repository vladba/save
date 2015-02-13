/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:03:34 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:11:01 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	while (s2[i] && (i < n))
	{
		s1[size + i] = s2[i];
		i++;
	}
	s1[size + i] = '\0';
	return (s1);
}
