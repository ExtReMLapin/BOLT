/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:18:44 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:25:14 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dp;
	const char		*sp;

	sp = s2;
	dp = s1;
	while (n--)
	{
		if (*sp == c)
		{
			*dp++ = *sp++;
			return (dp);
		}
		*dp++ = *sp++;
	}
	return (NULL);
}
