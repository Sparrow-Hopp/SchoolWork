#pragma once

#include <iostream>

class Trackable
{
public:
	void* operator new(std::size_t size);
	void operator delete(void *ptr);
	void* operator new[](std::size_t size);
	void operator delete[](void *ptr);

	//for use with placement new
	void* operator new(std::size_t size, void* ptr){ return ptr; };
	void operator delete(void *ptr, void*ptr2){};
	void* operator new[](std::size_t size, void* ptr){ return ptr; };
	void operator delete[](void *ptr, void* ptr2){};
};
