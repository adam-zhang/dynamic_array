#ifndef __ARRAY__H
#define __ARRAY__H

#include <stddef.h>



typedef struct 
{
	char* element;
	size_t size;
	size_t capacity;
	size_t element_size;
}array;

void array_init(array* a, size_t element_size);
void array_destroy(array* a);
void array_append(array* a, void* element);
void array_remove(array* a, void* element);
void output(array* a);
#endif//__ARRAY__H
