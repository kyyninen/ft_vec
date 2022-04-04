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
	printf("test_vec_new succesful!\n");
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

int ex03(void)
{
    t_vec   t1;
    t_vec   t2;
    int     base[] = {1, 2, 3, 4, 5};

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
    assert(vec_new(&t2, 5, sizeof(int)) > 0);
    assert(vec_copy(&t2, &t1) > 0);
    assert(memcmp(t2.memory, base, sizeof(base)) == 0);
    vec_free(&t1);
    vec_free(&t2);
	printf("test_vec_copy succesful!\n");
	return (1);
}

int ex04(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
    assert(vec_resize(&t1, 100) > 0);
    assert(memcmp(t1.memory, base, sizeof(base)) == 0);
    vec_free(&t1);
	printf("test_vec_resize succesful!\n");
	return (1);
}

int ex05(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};
    int     expect[] = {2, 4};

    assert(vec_new(&t1, 1, sizeof(int)) > 0);
    vec_push(&t1, &base[1]);
    vec_push(&t1, &base[3]);
    assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
    vec_free(&t1);
	printf("test_vec_push succesful!\n");
	return (1);
}

int main(void)
{
	ex00();
	ex01();
	ex02();
	ex03();
	ex04();
	ex05();
	return (0);
}
