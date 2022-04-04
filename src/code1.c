/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:27:40 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/01 18:34:16 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

/* Create a new vector from given parameters.
 * First check makes sure that size is more than 0 and it doesn't overflow.
 * Then we make sure that memory allocations were successful.
 */
int     vec_new(t_vec *src, size_t init_len, size_t elem_size)
{
	unsigned char	*mem;

	if (elem_size == 0 || init_len > (S_MAX / elem_size))
		return (-1);
	mem = ft_memalloc(init_len * elem_size);
	src->memory = mem;
	src->elem_size = elem_size;
	src->len = init_len;
	src->alloc_size = init_len * elem_size;
	return (1);
}

void    vec_free(t_vec *src)
{
	ft_memdel((void **)&(src->memory));
	src->len = 0;
	src->alloc_size = 0;
	src->elem_size = 0;
}

int     vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (vec_new(dst, len, elem_size) < 0)
		return (-1);
	ft_memcpy(dst->memory, (unsigned char *)src, len * elem_size);
	dst->elem_size = elem_size;
	dst->alloc_size = elem_size * len;
	dst->len = len;
	return (1);
}

int     vec_copy(t_vec *dst, t_vec *src)
{
	ft_memcpy(dst->memory, src->memory, (dst->alloc_size / src->elem_size) * src->elem_size);
	dst->elem_size = src->elem_size;
	dst->len = dst->alloc_size / src->elem_size; 
	return (1);
}

int     vec_resize(t_vec *src, size_t target_size)
{
	unsigned char	*new_mem;

	new_mem = ft_memalloc(target_size);
	if (!new_mem)
		return (-1);
	ft_memcpy(new_mem, src->memory, (target_size / src->elem_size) * src->elem_size);
	ft_memdel((void **)&(src->memory));
	src->memory = new_mem;
	src->alloc_size = target_size;
	return (1);
}
