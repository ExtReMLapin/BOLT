/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:47:06 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:24:25 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*c;

	if ((c = malloc(size)) == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
