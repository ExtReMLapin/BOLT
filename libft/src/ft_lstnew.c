/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 14:31:02 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 12:19:57 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lst;
	void	*cache;

	lst = (t_list*)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
	}
	else
	{
		cache = ft_memalloc(content_size);
		lst->content_size = content_size;
		lst->content = ft_memcpy(cache, (void*)content, content_size);
		lst->next = NULL;
	}
	return (lst);
}
