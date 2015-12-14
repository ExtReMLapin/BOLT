/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 15:19:37 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:23:09 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}


int	ft_strisdigit(char *str)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i2++;
		i++;	
	}
	if (i == i2)
		return (1);
	return (0);
}
