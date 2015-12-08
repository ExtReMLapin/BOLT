/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:24:55 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 12:15:08 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_nb_size(int i)
{
	int		counter;

	counter = 0;
	if (i < 0)
		counter++;
	while (i)
	{
		counter++;
		i /= 10;
	}
	return (counter);
}

char			*ft_itoa(int n)
{
	char	*nb;
	size_t	nbc;
	size_t	sign;
	size_t	v_absolu;
	size_t	i;

	nbc = ft_nb_size(n);
	i = nbc - 1;
	nb = (char*)malloc(sizeof(char) * (nbc + 1));
	sign = ((n < 0) ? 1 : 0);
	v_absolu = (unsigned)((n < 0) ? -n : n);
	if (!v_absolu)
	{
		nb[0] = '0';
		return (nb);
	}
	if (sign == 1)
		nb[0] = '-';
	while (v_absolu)
	{
		nb[i--] = '0' + (v_absolu % 10);
		v_absolu /= 10;
	}
	nb[nbc] = '\0';
	return (nb);
}
