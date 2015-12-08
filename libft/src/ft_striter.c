/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:09:02 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:48:04 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	index;

	index = 0;
	if (s && f)
	{
		while (s[index] != 0)
		{
			f(&s[index]);
			index++;
		}
	}
}
