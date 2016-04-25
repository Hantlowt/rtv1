/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:47:43 by hantlowt          #+#    #+#             */
/*   Updated: 2016/04/25 12:49:17 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	*init_light(t_vector pos, double power)
{
	t_light	*new;

	if (!(new = (t_light*)malloc(sizeof(t_light))))
		return (0);
	new->pos = pos;
	new->power = power;
	new->next = 0;
	return (new);
}

void		add_light(t_light *begin, t_light *new)
{
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}
