#include "array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void array_init(array* a, size_t element_size)
{
	a->element = malloc(10 * element_size);
	memset(a->element, 0, 10 * element_size);
	a->size = 0;
	a->capacity = 10;
	a->element_size = element_size;
}


void array_destroy(array* a)
{
	free(a->element);
	memset(a, 0, sizeof(array));
}

#define swap(a, b) \
	void* c = a; \
	a = b; \
	b = c; \

void extendMemeory(array* a)
{
	void* element = malloc(a->capacity * 2 * a->element_size);
	memcpy(element, a->element, a->element_size * a->capacity);
	swap(element, a->element);
	free(element);
	a->capacity = a->capacity * 2;
}

void array_append(array* a, void* e)
{
	if (a->size == a->capacity)
	{
		extendMemeory(a);
	}
	memcpy(&(a->element[a->size]), e, a->element_size);
	++a->size;
}

int equal(void* a, void* b, size_t size)
{
	char* ap = (char*)a;
	char* bp = (char*)b;
	for(size_t i = 0; i < size; ++i)
	{
		if (ap[i] != bp[i])
			return 0;
	}
	return 1;
}


static void remove_element(array* a, size_t index)
{
	for(size_t j = index ; j < a->size -1; ++j)
	{
		a->element[j] = a->element[j + 1];
	}
	a->element[a->size - 1] = 0;
}

void output(array* a)
{
	for(size_t i = 0; i < a->size; ++i)
	{
		char cc;
		memcpy(&cc, &(a->element[i]), a->element_size);
		printf("%c\n", cc);
	}
}

void array_remove(array* a, void* element)
{
	for(size_t i = 0; i < a->size; ++i)
	{
		if (equal(&a->element[i], element, a->element_size))
		{
			remove_element(a, i);
			--a->size;
			output(a);
			return;
		}
	}
}
