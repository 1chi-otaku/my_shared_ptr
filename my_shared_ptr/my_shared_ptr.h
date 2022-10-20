#pragma once
#include <iostream>
using namespace std;
template <class T>
class my_shared_ptr
{
	T* pointer = nullptr;  //A basic pointer.
	unsigned int* useCount = nullptr; //A pointer for references count to set the same value between objects of the my_shared_ptr object.

public:
	my_shared_ptr()
	{
		pointer = nullptr;
		useCount = new unsigned int (0);				//No params. constructor will allocate memory with int value 0.
	}
	my_shared_ptr(T* newpointer) {
		pointer = newpointer;
		useCount =  new unsigned int (1) ;				//If the user passes the pointer to the function, constructor will allocate memory with int value 1.
	}

	~my_shared_ptr() {
		clear_memory();
	}

	void clear_memory() {
		(*useCount)--;							//Decrement of count of references to the same memory area.
		if ((* useCount) == 0) {					// If there are no objects that point to the specific memory area, deletes pointer & useCount memory.
			if (nullptr != pointer)
				delete pointer;
			delete useCount;
		}
	}


	my_shared_ptr& operator=(const my_shared_ptr& obj) {
		
		clear_memory();
		this->pointer = obj.pointer; //Share the pointer
		this->useCount = obj.useCount; //Share the count of references pointer
		if (obj.pointer != nullptr) {
			(*this->useCount)++; //If obj_pointer isn't nullptr decrements useCount value.
		}


		return *this;
	}

	my_shared_ptr(const my_shared_ptr& obj) {
		pointer = obj.pointer; //Share the pointer
		useCount = obj.useCount; //Share the count of references pointer
		if (obj.pointer != nullptr) {
			(*this->useCount)++; //If obj_pointer isn't nullptr decrements useCount value
		}
		
	}


	T* get()const {
		return pointer;
	}
	int GetCount()const {
		return *useCount;
	}

};


