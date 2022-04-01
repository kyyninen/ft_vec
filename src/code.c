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
/*	new = ft_memalloc(sizeof(t_vec));
	if (!new)
	{
		return (-1);
	}
*/	mem = ft_memalloc(init_len * elem_size);
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

