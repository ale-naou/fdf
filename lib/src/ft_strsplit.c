/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:08:44 by ale-naou          #+#    #+#             */
/*   Updated: 2016/01/31 12:56:11 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_firstcharacs(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

static int	ft_wcount(const char *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (s[i] == '\0' || (s[i] != c && i == 0))
		counter++;
	while (s[i] != '\0')
	{
		i++;
		if (s[i] != c && s[i - 1] == c)
			counter++;
	}
	return (counter);
}

char		**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	j = 0;
	if (s == NULL || c == 0)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(s) * ft_wcount(s, c))) == NULL)
		return (NULL);
	i = ft_firstcharacs(s, c);
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i - 1] == c) || (s[i] != c && i == 0))
		{
			k = 0;
			while (s[i + k] != c && s[i + k] != '\0')
				k++;
			tab[j++] = ft_strsub(s, i, k);
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
