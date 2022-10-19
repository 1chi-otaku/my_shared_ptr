#pragma once
#include <iostream>
using namespace std;
template <class T>
class my_shared_ptr
{
	T* pointer = nullptr;
	int* useCount = nullptr;

public:
	my_shared_ptr()
	{
		pointer = nullptr;
		useCount = new int(0);
	}
	my_shared_ptr(T* newpointer) {
		pointer = newpointer;
		useCount = new int(1);
	}

	~my_shared_ptr() {
		(*useCount)--;
		if (*useCount == 0) {
			if (pointer != nullptr)
				delete pointer;
			delete useCount;
		}
	}




	my_shared_ptr& operator=(const my_shared_ptr& obj) {
		
		(*useCount)--;
		if (*useCount == 0)
		{
			if (nullptr != pointer)
				delete pointer;
			delete useCount;
		}

		pointer = obj.pointer; //Share the pointer
		useCount = obj.useCount; //Share the count of references pointer
		if (obj.pointer != nullptr) (*useCount)++; //If obj_pointer isn't nullptr decrements useCount value.
		return *this;

	}

	my_shared_ptr(const my_shared_ptr& obj) {
		pointer = obj.pointer; //Share the pointer
		useCount = obj.useCount; //Share the count of references pointer
		if (obj.pointer != nullptr)(*useCount)++; //If obj_pointer isn't nullptr decrements useCount value
		
	}

	T* operator->() const
	{
		return pointer;
	}

	T& operator*() const
	{
		return pointer;
	}

	T* get() {
		return pointer;
	}
	int GetCount() {
		return *useCount;
	}

};


