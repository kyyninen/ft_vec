#include "vec.h"
#include <assert.h>
#include <stdio.h>

int ex00(void)
{
	t_vec t1;

	assert(vec_new(&t1, 0, 0) == -1);
	assert(vec_new(&t1, 0, 1) > 0);
	assert(t1.memory == NULL);
	assert(vec_new(&t1, 1, 0) == -1);
	assert(vec_new(&t1, 10, 1) > 0);
	assert(t1.memory != NULL);
    vec_free(&t1);
	printf("test_vec_new successful!\n");
	return (1);
}

int ex01(void)
{
	t_vec t1;

    assert(vec_new(&t1, 10, 1) > 0);
    vec_free(&t1);
    assert(t1.len == 0);
    assert(t1.alloc_size == 0);
    assert(t1.elem_size == 0);
    assert(t1.memory == NULL);
	printf("test_vec_free succesful!\n");
	return(1);
}

int ex02(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
    assert(ft_memcmp(t1.memory, base, sizeof(base)) == 0);
    vec_free(&t1);
	printf("test_vec_from succesful!\n");
	return (1);
}

int main(void)
{
	ex00();
	ex01();
	ex02();
	return (0);
}
