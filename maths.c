/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:16:04 by alhote            #+#    #+#             */
/*   Updated: 2016/04/25 17:54:02 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double			efmod(double a, double base)
{
	return (a < 0.0 ? fmod(((fmod(a, base)) + base), base) : fmod(a, base));
}

double			torad(double degree)
{
	return (PI * degree / 180.0);
}

double			cosd(double v)
{
	return (cos(PI * v / 180.0));
}

double			sind(double v)
{
	return (sin(PI * v / 180.0));
}
