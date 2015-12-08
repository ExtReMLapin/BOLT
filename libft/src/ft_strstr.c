/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 17:58:29 by pfichepo          #+#    #+#             */
/*   Updated: 2015/11/24 14:41:50 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (!s2[i])
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == s2[i])
		{
			while (*s1 == s2[i] && s2[i])
			{
				s1++;
				i++;
			}
			s1 -= i;
			if (!s2[i])
				return ((char *)s1);
			i = 0;
		}
		s1++;
	}
	return (NULL);
}
