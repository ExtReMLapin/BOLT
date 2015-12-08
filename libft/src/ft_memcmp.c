/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:00:56 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:25:29 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n && *((unsigned char *)s1) == *((unsigned char *)s2))
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
	if (n)
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	return (0);
}
