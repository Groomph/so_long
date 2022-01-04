/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:56:05 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/08 12:58:59 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_block(int cursor)
{
	return (cursor + BLOCK_SIZE);
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
