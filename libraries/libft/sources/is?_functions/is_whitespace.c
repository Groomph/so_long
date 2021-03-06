/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:30:42 by romain            #+#    #+#             */
/*   Updated: 2021/07/26 14:43:54 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f'
		|| c == '\n' || c == '\r' || c == '\v')
		return (TRUE);
	return (FALSE);
}
