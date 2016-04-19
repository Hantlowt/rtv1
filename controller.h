/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 11:33:05 by hantlowt          #+#    #+#             */
/*   Updated: 2016/04/14 18:05:58 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H
# include <stdio.h>
# include <stdlib.h>
# ifdef __APPLE__
#  define ESC 53
#  define RIGHT 124
#  define LEFT 123
#  define UP 126
#  define DOWN 125
#  define SPACE 49
#  define LETTER_T 17
# elif defined __linux__
#  define ESC 65307
#  define RIGHT 65363
#  define LEFT 65361
#  define UP 65362
#  define DOWN 65364
#  define SPACE 32
#  define LETTER_T 116
# endif

int	keyboard(int keycode, void *data);
#endif
