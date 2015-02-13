/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:01:10 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:46:04 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int n)
{
	int		i;

	i = ft_strlen(s);
	while (s[i] != (char)n && i)
		i--;
	if (s[i] == (char)n)
		return ((char *)(s + i));
	return (NULL);
}
