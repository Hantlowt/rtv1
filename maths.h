/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:21:03 by alhote            #+#    #+#             */
/*   Updated: 2016/04/25 18:40:51 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H
# include <math.h>
# define PI 3.14159265359

typedef struct	s_vector
{
	double			x;
	double			y;
	double			z;
}				t_vector;
t_vector		vect(double x, double y, double z);
t_vector		rotate(t_vector v, double o, char a);
double			efmod(double a, double base);
double			torad(double degree);
double			cosd(double v);
double			sind(double v);
double			dist(t_vector A, t_vector B);
t_vector		cross_product(t_vector A, t_vector B);
t_vector		transformation_vector(t_vector forward, t_vector B);
#endif