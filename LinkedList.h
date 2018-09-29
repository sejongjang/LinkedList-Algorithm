#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "LinkedListInterface.h"
#define STARTSIZE 4

using namespace std;
template<class T>

class LinkedList : public LinkedListInterface<T> {
private:
	struct Node {
		T data;
		Node* next;
		Node(T& the_data, Node* next_val = NULL) {
			data = the_data;
			next = next_val;
		}
	};

	Node* h;
	int num_items;

public:
	LinkedList() {
		num_items = 0;
	}
	~LinkedList() {
		clear();
	}

	bool dupCheck(T value) {
		Node* t = h;
		while (t->data != value) {
			t = t->next;
			if (t == NULL) {
				return true;
			}
		}
		return false;
	}

	void insertHead(T value) {
		if (num_items == 0) {
			Node* newnode = new Node(value, NULL);
			h = newnode;
			num_items++;
		}
		else {
			if (dupCheck(value) == true) {
				Node* newnode = new Node(value, NULL);
				newnode->next = h;
				h = newnode;
				num_items++;
			}
		}
	}

	void insertTail(T value) {
		if (num_items == 0) {
			insertHead(value);
		}
		else {
			if (dupCheck(value) == true) {
				Node* newnode = new Node(value, NULL);
				Node* t = h;
				while (t->next != NULL) {
					t = t->next;
				}
				t->next = newnode;
				num_items++;
			}
		}
	}

	void insertAfter(T value, T insertionNode) {
		if (dupCheck(value) == true) {
			Node* t = h;
			while (t->data != insertionNode) {
				t = t->next;
				if (t == NULL) {
					return;
				}
			}
			Node* newnode = new Node(value, NULL);
			newnode->next = t->next;
			t->next = newnode;
			num_items++;
		}
	}

	void remove(T value) {
		if (h->data == value) {
			Node* removePtr = h;
			h = removePtr->next;
			delete removePtr;
			num_items--;
		}
		else {
			Node* t = h;
			while (t->next->data != value) {
				t = t->next;
				if (t->next == NULL) {
					return;
				}
			}
			Node* removePtr;
			removePtr = t->next;
			t->next = t->next->next;
			delete removePtr;
			num_items--;
		}
	}

	T at(int index) {
		T thing;
		if ((index >= num_items) || (index < 0)) {
			cout << "out of range" << endl;
		}
		else {
			Node* ptr = h;
			for (int i = 0; i < num_items; ++i) {
				if (index == i) {
					thing = ptr->data;
					return thing;
				}
				else {
					ptr = ptr->next;
				}
			}
		}
	};

	int size() {
		return num_items;
	}

	void clear() {
		while (h != NULL) {
			Node* current = h;
			h = h->next;
			delete current;
			num_items--;
		}
	}

	string toString() {
		if (h == NULL) {
			return "";
		}
		
		stringstream ss;

		for (Node* ptr = h; ptr != NULL; ptr = ptr->next) {
			ss << ptr->data << " ";
		}
		
		return ss.str();
	}
};