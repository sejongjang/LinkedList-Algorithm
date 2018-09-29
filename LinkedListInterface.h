#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;
template<typename T>

class LinkedListInterface {
public:
	LinkedListInterface() {

	};

	virtual ~LinkedListInterface() {

	};

	virtual void insertHead(T value) = 0;
	virtual void insertTail(T value) = 0;
	virtual void insertAfter(T value, T insertionNode) = 0;
	virtual void remove(T value) = 0;
	virtual void clear() = 0;
	virtual T at(int index) = 0;
	virtual int size() = 0;
	virtual string toString() = 0;

};