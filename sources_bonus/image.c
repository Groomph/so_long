/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:56:05 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/05 18:51:43 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_block(int cursor)
{
	return (cursor + BLOCK_SIZE);
}

int	next_block_xtimes(int cursor, int nb)
{
	while (nb > 0)
	{
		cursor = next_block(cursor);
		nb--;
	}
	return (cursor);
}

int	block_line_feed(t_img *img, int cursor)
{
	cursor -= (cursor % BLOCK_SIZE);
	return (next_line(img, cursor));
}

int	next_line(t_img *img, int cursor)
{
	return (cursor + img->size_x);
}

int	next_line_xtimes(t_img *img, int cursor, int nb)
{
	while (nb > 0)
	{
		cursor = next_line(img, cursor);
		nb--;
	}
	return (cursor);
}
