/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:57:43 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:32:50 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	c;

	if (len > 0)
	{
		c = *((const char *)src);
		ft_memmove((char *)(dst) + 1, (char *)(src) + 1, len - 1);
		*((char *)dst) = c;
	}
	return (dst);
}
