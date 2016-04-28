/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:37:27 by hantlowt          #+#    #+#             */
/*   Updated: 2016/04/28 09:19:56 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsv.h"

t_hsv			hsv(int h, int s, int v)
{
	t_hsv	n;

	n.hue = h;
	n.saturation = s;
	n.value = v;
	return (n);
}

int				hsvtorgb(t_hsv c)
{
	int v;
	int m;
	int sextant;
	int fract, vsf, mid1, mid2;
	int	r;
	int	g;
	int	b;

	r = g = b = 0;
	v = (c.value < 128) ? (c.value * (256 + c.saturation)) >> 8 :
	(((c.value + c.saturation) << 8) - c.value * c.saturation) >> 8;
	if (v <= 0) {
	r = g = b = 0;
	}
	else
	{
		m = c.value + c.value - v;
		c.hue *= 6;
		sextant = c.hue >> 8;
		fract = c.hue - (sextant << 8);
		vsf = v * fract * (v - m) / v >> 8;
		mid1 = m + vsf;
		mid2 = v - vsf;
		switch (sextant) {
			case 0: r = v; g = mid1; b = m; break;
			case 1: r = mid2; g = v; b = m; break;
			case 2: r = m; g = v; b = mid1; break;
			case 3: r = m; g = mid2; b = v; break;
			case 4: r = mid1; g = m; b = v; break;
			case 5: r = v; g = m; b = mid2; break;
		}
	}
	return (r * 65536 + g * 256 + b);
}
