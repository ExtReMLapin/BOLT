/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:25:31 by pfichepo          #+#    #+#             */
/*   Updated: 2015/11/18 19:41:40 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <unistd.h>

size_t			count_words(char const *s, char sep)
{
	size_t		word;

	word = 0;
	while (s && *s)
	{
		if (*s == sep)
			word++;
		while (*s == sep)
			s++;
		s++;
	}
	return (word);
}

static int		letters(char const *s, char c, int count)
{
	int	letters;

	letters = 0;
	while (s[count] != c && s[count] != '\0')
	{
		letters++;
		count++;
	}
	return (letters);
}

static int		skip_char(char const *s, char c, int count)
{
	while (s[count] == c && s[count] != '\0')
		count++;
	if (s[count] == '\0')
		return (-1);
	return (count);
}

static void		ft_tab(char **tab, char c, char const *s)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (s[count] != '\0' && (skip_char(s, c, count) != -1))
	{
		j = 0;
		count = skip_char(s, c, count);
		tab[i] = (char *)malloc((letters(s, c, count) + 1) * sizeof(char));
		if (tab[i] != NULL)
		{
			while (s[count] != c && s[count] != '\0')
			{
				tab[i][j] = s[count];
				j++;
				count++;
			}
			tab[i][j] = '\0';
			i++;
		}
	}
	tab[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	tab = NULL;
	if (s)
	{
		words = count_words(s, c);
		tab = (char **)malloc((words + 1) * sizeof(char *));
		if (tab)
			ft_tab(&(*tab), c, s);
	}
	return (tab);
}
