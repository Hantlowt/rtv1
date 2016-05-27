/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:21:03 by alhote            #+#    #+#             */
/*   Updated: 2016/05/27 18:59:34 by alhote           ###   ########.fr       */
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
double			efmod(double a, double base);
double			torad(double degree);
double			cosd(double v);
double			sind(double v);
double			dist(t_vector a, t_vector b);
t_vector		norm_vect(t_vector v);
t_vector		cross_product(t_vector a, t_vector b);
t_vector		transformation_vector(t_vector forward, t_vector ref);
double			get_cosangle(t_vector a, t_vector b, t_vector c);
t_vector		add_vect(t_vector a, t_vector b);
t_vector		sub_vect(t_vector a, t_vector b);
double			dot_vect(t_vector a, t_vector b);
#endif
