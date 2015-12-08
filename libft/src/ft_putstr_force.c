/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_force.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 15:46:21 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/21 15:50:36 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_force(char const *s, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(s[i]);
		i++;
	}
}
