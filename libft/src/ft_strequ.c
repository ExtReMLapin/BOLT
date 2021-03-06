/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:55:49 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:47:59 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return ((ft_strcmp(s1, s2) == 0 ? 1 : 0));
	return (0);
}
