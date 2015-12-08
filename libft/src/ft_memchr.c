/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:04:10 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:25:19 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	counter;
	char			*found;
	char			*driver;
	char			c1;

	c1 = (unsigned char)c;
	counter = 0;
	driver = (char *)s;
	found = NULL;
	while (found == NULL && counter < n)
	{
		if (driver[counter] == c1)
			found = &(driver[counter]);
		counter++;
	}
	return (found);
}
