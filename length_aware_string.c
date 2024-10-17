int get_capacity_for_string_length(int len) {
	int new_capacity = 256; // 64 UTF-32 chars

	while (new_capacity > len) {
		new_capacity *= 2;
	}

	return new_capacity + 1;
}

int get_length_of_cstr(char* cstr) {
	int length = 0;

	while (*cstr != '\0') {
		length++;
		cstr++;
	}

	return length;
}

void copy_memory(char* src, size_t len, char* dst) {
	for (int i = 0; i < len; i++) {
		dst[i] = src[i];
	}
}

length_aware_string* create_empty_length_aware_string(allocator_dependency_package allocator_pack) {
	length_aware_string* str = allocator_pack->allocate(allocator->allocator, sizeof(length_aware_string));

	str->length = 0;
	str->capacity = get_capacity_for_string_length(str->length);
	str->cstr = allocator_pack->allocate(allocator->allocator, sizeof(char) * str->capacity);

	return str;
}

length_aware_string* create_length_aware_string_from_cstr(
	allocator_dependency_package allocator_pack, 
	char* cstr
) {
	length_aware_string* str = allocator_pack->allocate(allocator->allocator, sizeof(length_aware_string));

	str->length = get_length_of_cstr(cstr);
	str->capacity = get_capacity_for_string_length(str->length);
	str->cstr = allocator_pack->allocate(allocator->allocator, sizeof(char) * str->capacity);

	copy_memory(cstr, str->length, str->cstr);
	str->cstr[str->length] = '\0';

	return str;
}

length_aware_string* clone_length_aware_string(
	allocator_dependency_package allocator_pack,
	length_aware_string* instance
) {
	return create_length_aware_string_from_cstr(allocator_pack, instance->cstr);
}

void destroy_length_aware_string(length_aware_string* instance) {
	instance->allocator->deallocate_memory(instance->cstr);
	instance->allocator->deallocate_memory(instance);
}