/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 14:41:11 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/19 10:16:57 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_isnotgood(int c)
{
	if (((c >= '0') && (c <= '9')) || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char		*str_replace(char *orig, char *rp, char *wt)
{
	char	*rt;
	char	*ins;
	char	*t;
	int		len_front;
	int		cnt;

	if (!rp || !wt || !orig)
		return (orig);
	ins = orig;
	cnt = 0;
	while ((t = ft_strstr(ins, rp)) != NULL && cnt++)
		ins = t + ft_strlen(rp);
	t = (char*)malloc(sizeof(char) * (ft_strlen(orig) + \
		(ft_strlen(wt) - ft_strlen(rp)) * cnt + 1));
	rt = t;
	while (cnt--)
	{
		ins = ft_strstr(orig, rp);
		len_front = ins - orig;
		t = ft_strncpy(t, orig, len_front) + len_front;
		t = ft_strcpy(t, wt) + ft_strlen(wt);
		orig += len_front + ft_strlen(rp);
	}
	ft_strcpy(t, orig);
	return (rt);
}

char		*str_replace2(char *orig, char *rp, char *wt)
{
	if (!rp || !wt || !orig)
		return ("");
	while (ft_strstr(orig, rp) != NULL)
		orig = str_replace(orig, rp, wt);
	return (orig);
}

static int	cheaterlines(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_isnotgood(str[i]) || ((str[i] == '-' && ft_isdigit(str[i + 1]))))
			len++;
		i++;
	}
	return (len);
}

char		*rem_nonnum(char *str)
{
	int		i;
	char	*to_return;
	int		len;

	i = 0;
	len = cheaterlines(str);
	to_return = (char *)malloc(sizeof(char) * (len + 1));
	if (to_return == NULL)
		error("MALLOC FAIL ON rem_nonnum");
	len = 0;
	while (str[i])
	{
		if (ft_isnotgood(str[i]) || ((str[i] == '-' && ft_isdigit(str[i + 1]))))
		{
			to_return[len] = str[i];
			len++;
		}
		i++;
	}
	to_return[len] = '\0';
	return (to_return);
}
