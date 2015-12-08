/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:36:47 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:48:26 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p_dest;

	p_dest = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && n--)
		*dest++ = *src++;
	*dest = '\0';
	return (p_dest);
}
