/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_string_duplicate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:30:14 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/08 15:26:17 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**array_string_duplicate(char **tab, int size)
{
	char	**tmp;
	int		i;

	if (size < 0)
	{
		size = 0;
		while (tab[size])
			size++;
	}
	tmp = malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	tmp[size] = NULL;
	i = 0;
	while (i < size)
	{
		tmp[i] = string_duplicate(tab[i], -1);
		if (!(tmp[i]))
		{
			array_clear((void **)tmp);
			return (NULL);
		}
		i++;
	}
	return (tmp);
}
