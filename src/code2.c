/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:27:26 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/03 15:54:49 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h" 

int		vec_alloc_check(t_vec *vec, int elems_to_add)
{
	int	elems_left;

	elems_left = vec->len - (vec->alloc_size / vec->elem_size);
	if (elems_left <= elems_to_add)
	{
		return (vec_resize(vec, vec->alloc_size));
	}
	return (0);
}

int     vec_push(t_vec *vec, void *src)
{
	if (vec_alloc_check(vec, 1) < 0)
	{
		return (-1);
	}
	ft_memcpy(vec->memory + (vec->len * vec->elem_size), src, vec->elem_size);
	return (1);
}
