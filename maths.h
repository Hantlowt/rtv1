/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:21:03 by alhote            #+#    #+#             */
/*   Updated: 2016/04/21 15:37:11 by alhote           ###   ########.fr       */
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
#endif
