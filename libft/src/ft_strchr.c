/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:19:06 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:27:36 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strchr(const char *s, int c)
{
	char		to_find;
	char		*found;
	int			count;

	to_find = c;
	found = NULL;
	count = 0;
	while (s[count] != '\0' && found == NULL)
	{
		if (s[count] == to_find)
			found = (char *)(s + count);
		count++;
	}
	if (s[count] == to_find && found == NULL)
		found = (char *)(s + count);
	return (found);
}
