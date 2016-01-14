/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 19:26:38 by pfichepo          #+#    #+#             */
/*   Updated: 2015/12/03 15:54:09 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <unistd.h>

static void		ft_free_one(t_slist **begin_list)
{
	t_slist	*to_free;

	to_free = *begin_list;
	*begin_list = to_free->next;
	free(to_free);
	to_free = NULL;
}

static t_slist	*ft_list_push_front(t_slist *begin_list, char c, int fd, int n)
{
	t_slist	*list;
	t_slist	*rev;

	list = (t_slist *)malloc(sizeof(t_slist));
	if (!list)
		return (NULL);
	list->fd = fd;
	list->c = c;
	if (!begin_list)
		list->next = NULL;
	else
		list->next = begin_list;
	if (n == 0)
	{
		rev = NULL;
		while (list)
		{
			rev = ft_list_push_front(rev, list->c, fd, 1);
			ft_free_one(&list);
		}
		return (rev);
	}
	return (list);
}

static t_slist	*ft_read(int fd)
{
	int		ret;
	int		n;
	char	*buf;
	t_slist	*bro_l;

	if (BUFF_SIZE > 2147483647 || BUFF_SIZE < 1)
		return (NULL);
	bro_l = NULL;
	ret = -1;
	while (ret)
	{
		if (!(buf = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (NULL);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (NULL);
		n = -1;
		while (++n < ret)
		{
			if (buf[n] != '\0')
				bro_l = ft_list_push_front(bro_l, buf[n], fd, 1);
		}
	}
	bro_l = ft_list_push_front(bro_l, '\0', fd, 0);
	return (bro_l);
}

static int		ft_linelen(t_slist *begin_list)
{
	int		len;
	t_slist	*browse_list;

	browse_list = begin_list;
	len = 0;
	while (browse_list && browse_list->c)
	{
		len++;
		browse_list = browse_list->next;
	}
	return (len);
}

char			**file_totbl(char *file)
{
	t_slist	*list;
	char	*textn;
	char	**textf;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	list = ft_read(fd);
	textn = (char *)malloc(sizeof(char) * (ft_linelen(list) + 1));
	while (list && list->c)
	{
		textn[i] = list->c;
		list = list->next;
		i++;
	}
	textn = rem_nonnum(textn);
	textf = ft_strsplit(textn, '\n');
	return (textf);
}
