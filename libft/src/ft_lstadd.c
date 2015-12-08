/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 15:13:58 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:46:02 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list		*alst_tmp;

	if (new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		alst_tmp = *alst;
		new->next = alst_tmp;
		*alst = new;
	}
}
