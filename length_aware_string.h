#ifndef LENGTH_AWARE_STRING_H_
#define LENGTH_AWARE_STRING_H_

#include <allocators.h>

struct length_aware_string {
	char* cstr;
	int length;
	int capacity;
};

typedef struct length_aware_string length_aware_string;

length_aware_string* create_empty_length_aware_string(allocator_dependency_package allocator_pack);

length_aware_string* create_length_aware_string_from_cstr(
	allocator_dependency_package allocator_pack,
	char* cstr
);

length_aware_string* clone_length_aware_string(
	allocator_dependency_package allocator_pack,
	length_aware_string* instance
);

void destroy_length_aware_string(length_aware_string* instance);

#endif