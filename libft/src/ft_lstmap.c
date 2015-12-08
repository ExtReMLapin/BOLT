/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 15:16:51 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:46:21 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*new;

	if (lst && *f)
	{
		new = (f)(lst);
		if (new && lst->next)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
