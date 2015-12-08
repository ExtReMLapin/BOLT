/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:45:08 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:47:56 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		i2;
	char	*output;

	i2 = ft_strlen(s1);
	i = 0;
	output = (char *)malloc(sizeof(char) * (i2 + 1));
	if (output == NULL)
		return (NULL);
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
