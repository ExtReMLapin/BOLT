/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:22:37 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:48:40 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len2;
	int			i;
	char		*str;

	len2 = ft_strlen(s2);
	i = 0;
	str = (char*)s1;
	i = n - len2 + 1;
	if (s1 && s2)
	{
		if (ft_strlen(s1) < len2)
			return (NULL);
		if (!len2)
			return (str);
		if (n < len2)
			return (NULL);
		while (i)
		{
			if (!ft_strncmp(str, s2, len2))
				return (str);
			str++;
			i--;
		}
	}
	return (NULL);
}
