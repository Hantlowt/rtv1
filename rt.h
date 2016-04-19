/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:14:06 by alhote            #+#    #+#             */
/*   Updated: 2016/04/19 18:09:24 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_world
{
	void	*mlx;
	void	*win;
	void	*img;
	int		screen_x;
	int		screen_y;
}				t_world;
t_world			*init_world(int x, int y);
void			render(t_world *w);
#endif
