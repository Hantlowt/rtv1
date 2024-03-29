/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:50:06 by alhote            #+#    #+#             */
/*   Updated: 2016/05/24 16:48:10 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object	*init_obj(t_vector pos, t_hsl color)
{
	t_object	*new;

	if (!(new = (t_object*)malloc(sizeof(t_object))))
		return (0);
	new->pos = pos;
	new->color = color;
	new->diffuse = 30.0;
	new->specular = 0.0;
	new->next = 0;
	return (new);
}

t_object	*add_obj(t_object *begin, t_object *new)
{
	while (begin->next)
		begin = begin->next;
	begin->next = new;
	return (new);
}
