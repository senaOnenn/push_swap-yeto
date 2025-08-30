/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:52:51 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 17:29:00 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr,size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t i = 0, j = 0, k, word_count = 0;
	char **res;

	if (!s)
		return (NULL);

	// kelime sayısı
	for (i = 0; s[i]; i++)
		if ((s[i] != c && (i == 0 || s[i - 1] == c)))
			word_count++;

	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);

	i = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		res[j] = malloc(i - k + 1);
		if (!res[j])
			return (free_arr(res, j), NULL);
		for (size_t x = 0; x < i - k; x++)
			res[j][x] = s[k + x];
		res[j][i - k] = '\0';
		j++;
	}
	res[j] = NULL;
	return (res);
}

