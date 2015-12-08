/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 12:58:51 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:32:57 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char		*p;
	size_t		i;

	p = dst;
	i = 0;
	while (i < n && dst && src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n && dst && src)
	{
		dst[i] = '\0';
		i++;
	}
	return (p);
}
