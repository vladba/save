/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 13:20:46 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/04 18:07:34 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		nbr;
	int		neg;

	nbr = 0;
	neg = 1;
	while ((*str < 14 && *str > 8) || *str == ' ')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (*str == '+' && neg == 1)
		str++;
	while (*str != '\0' && *str <= '9' && *str >= '0')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	nbr = nbr * neg;
	return (nbr);
}
