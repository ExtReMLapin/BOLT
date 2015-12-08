/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 21:38:56 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:48:28 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		c1;
	int		c2;

	i = 0;
	while ((s1[i] || s2[i]) && n-- > 0)
	{
		if (s1[i] != s2[i])
		{
			c1 = s1[i];
			c2 = s2[i];
			if (s1[i] < 0)
				c1 *= -1;
			if (s2[i] < 0)
				c2 *= -1;
			return ((int)(c1 - c2));
		}
		i++;
	}
	return (0);
}
