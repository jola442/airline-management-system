
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {
	template <class V>
	friend ostream& operator << (ostream& out, const Array<V>& arr);
	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other member functions
		void add(T);
		T& operator[](int index);
		int getSize();
		bool isEmpty();
	
	private:
		int size;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize(){
	return size;
}

template <class T>
bool Array<T>::isEmpty(){
	return size == 0;
}

template <class T>
T& Array<T> :: operator[](int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
ostream& operator << (ostream& out, const Array<T>& arr){
	for(int i = 0; i < arr.size; ++i){
		out << arr.elements[i] << endl;
	}
	return out;
}

#endif