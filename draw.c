/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:13:10 by alhote            #+#    #+#             */
/*   Updated: 2016/05/24 14:22:39 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	img_pxl(void *img, int x, int y, int color)
{
	int		*data;
	int		bpp;
	int		sizeline;
	int		endian;

	data = (int*)mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	data[y * (sizeline / 4) + x] = color;
}
