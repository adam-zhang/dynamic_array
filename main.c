#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

void testInitialization()
{
	array a;
	char* s = "Hello world!";
	array_init(&a, sizeof(char));
	printf("size:%lu, capacity:%lu, element_size:%lu, element:%lu\n",
			a.size,
			a.capacity,
			a.element_size,
			(size_t)a.element);
	array_destroy(&a);
	printf("size:%lu, capacity:%lu, element_size:%lu, element:%lu\n",
			a.size,
			a.capacity,
			a.element_size,
			(size_t)a.element);
}


void testAppend()
{
	char* str = "Hello world!";
	size_t length = strlen(str);
	array a;
	array_init(&a, sizeof(char));
	for(size_t i = 0; i < length; ++i)
	{
		array_append(&a, &str[i]);
	}
	for(size_t i = 0; i < a.size; ++i)
	{
		//char* cp = (char*)&a.element[i];
		char c;
		memcpy(&c, &a.element[i], a.element_size);
		printf("%c", c);
	}
	printf("\n");
	printf("capacity:%lu\n", a.capacity);
	array_destroy(&a);
}

void testRemove()
{
	char* str = "Hello World!";
	size_t length = strlen(str);
	array a;
	array_init(&a, sizeof(char));
	for(size_t i = 0; i < length; ++i)
	{
		array_append(&a, &str[i]);
	}

	char c = 'H';
	array_remove(&a,&c );
	output(&a);
	for(size_t i = 0; i < a.size; ++i)
	{
		char cc;
		memcpy(&cc, &(a.element[i]), a.element_size);
		printf("%c", cc);
	}
	printf("\n");
	printf("size:%lu\n", a.size);
	array_destroy(&a);
}


void testArray()
{
	testInitialization();
	testAppend();
	testRemove();
}

int main(int argc, char** argv)
{
	testArray();
	return 0;
}
