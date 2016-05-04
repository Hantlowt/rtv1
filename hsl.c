/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:37:27 by hantlowt          #+#    #+#             */
/*   Updated: 2016/05/04 14:30:07 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl.h"

t_hsl			hsl(int h, double s, double l)
{
	t_hsl	n;

	n.h = h;
	n.s = s / 100.0;
	n.l = l / 100.0;
	return (n);
}

static double	huetorgb(double v1, double v2, double vh)
{
	if (vh < 0)
		vh += 1;
	if (vh > 1)
		vh -= 1;
	if ((6 * vh) < 1)
		return (v1 + (v2 - v1) * 6 * vh);
	if ((2 * vh) < 1)
		return (v2);
	if ((3 * vh) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vh) * 6);
	return (v1);
}

int				hsltorgb(t_hsl c)
{
	int		rgb[3];
	double	v[2];
	double	hue;

	c.h = (c.h > 360.0 ? 360.0 : c.h);
	c.s = (c.s > 1.0 ? 1.0 : c.s);
	c.l = (c.l > 1.0 ? 1.0 : c.l);
	c.h = (c.h < 0 ? 0 : c.h);
	c.s = (c.s < 0 ? 0 : c.s);
	c.l = (c.l < 0 ? 0 : c.l);
	if (c.s == 0)
	{
		rgb[0] = (unsigned char)(c.l * 255);
		rgb[1] = rgb[0];
		rgb[2] = rgb[0];
	}
	else
	{
		hue = (float)c.h / 360;
		v[1] = (c.l < 0.5) ? (c.l * (1 + c.s)) : ((c.l + c.s) - (c.l * c.s));
		v[0] = 2 * c.l - v[1];
		rgb[0] = (unsigned char)(255 * huetorgb(v[0], v[1], hue + (1.0f / 3)));
		rgb[1] = (unsigned char)(255 * huetorgb(v[0], v[1], hue));
		rgb[2] = (unsigned char)(255 * huetorgb(v[0], v[1], hue - (1.0f / 3)));
	}
	return (rgb[0] * 65536 + rgb[1] * 256 + rgb[2]);
}
