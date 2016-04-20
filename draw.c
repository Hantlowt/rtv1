/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:13:10 by alhote            #+#    #+#             */
/*   Updated: 2016/04/20 18:13:47 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	img_pxl(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	data[y * sizeline + x * 4] = color;
	data[y * sizeline + x * 4 + 1] = color >> 8;
	data[y * sizeline + x * 4 + 2] = color >> 16;
}
