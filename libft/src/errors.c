/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 02:04:55 by pfichepo          #+#    #+#             */
/*   Updated: 2015/11/04 17:17:30 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	error(const char *s)
{
	ft_putstr("\033[1;31m");
	ft_putstr("[FATAL ERROR] : ");
	ft_putstr(s);
	ft_putstr("]\033[0m");
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

void	errornohalt(const char *s)
{
	ft_putstr("\033[1;31m");
	ft_putstr("[SPOOKY ERROR] : ");
	ft_putstr(s);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}
