/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:41:35 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/09 15:10:50 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = -1;
	str = ft_strdup(s);
	while (s[++i])
		str[i] = (*f)(s[i]);
	return (str);
}
