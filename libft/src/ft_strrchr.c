/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:29:12 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:48:44 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strrchr(const char *s, int c)
{
	char		to_find;
	char		*found;
	int			count;

	to_find = c;
	found = NULL;
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == to_find)
			found = (char *)(s + count);
		count++;
	}
	if (s[count] == to_find)
		found = (char *)(s + count);
	return (found);
}
