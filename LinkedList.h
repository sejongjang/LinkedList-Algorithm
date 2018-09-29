#include "LinkedListInterface.h" 
#include <stdexcept> 
#include <sstream> 
using namespace std; 
#define STARTSIZE 4 
template <class T>

class LinkedList: public LinkedListInterface<T> {
private: 
	struct Node {
		T data;
		Node* next; 
		Node(const T& the_data, Node* next_val = NULL) : 
			data(the_data) {next = next_val;}
	}; 
	
	Node* head; 
	int num_items; 
	
public: 
	LinkedList(void) {
		head = NULL; 
		num_items = 0; 
	}; 
	~LinkedList() {
		clear(); 
	};
	
	bool dupCheck (T value) {
		Node* temp = head; 
		while (temp -> data != value) {
			temp = temp -> next; 
			if (temp == NULL) {
				return true; 
			}
		}
		return false; 
	}; 
	
	
	void insertHead(T value) {
		if (num_items == 0) {
			Node* newnode = new Node (value, NULL); 
			head = newnode; 
			num_items++; 
			return; 
		}
		else {
			if (dupCheck(value) == true) {
				Node* newnode = new Node (value, NULL); 
				newnode -> next = head; 
				head = newnode; 
				num_items++; 
				return; 
			}
			else {
				return; 
			}
		}
	}; 
	
	void insertTail(T value) {
		if (num_items == 0) {
			insertHead(value); 
		}
		else {
			if (dupCheck(value) == true) {
				Node* newnode = new Node (value, NULL); 
				Node* temp = head; 
				while (temp -> next != NULL) {
					temp = temp -> next; 
				}
				temp -> next = newnode; 
				num_items++; 
				return; 
			}
			else {
				return; 
			}
		}
	}; 
	
	void insertAfter(T value, T insertionNode) {
		if (num_items == 0) {
			return;  
		}
		else {
			if (dupCheck(value) == true) {
				Node* temp = head;
				while (temp -> data != insertionNode) {
					temp = temp -> next; 
					if (temp == NULL) {
						return; 
					}
				}
				Node* newnode = new Node(value, NULL); 
				newnode -> next = temp -> next; 
				temp -> next = newnode; 
				num_items++; 
				return; 
			}
			else {
				return; 
			}
		}
	}; 
	
	void remove(T value) {
		if (num_items == 0) {
			return;  
		}
		else {
			if (head -> data == value) {
				Node* stuff = head; 
				head = stuff -> next; 
				delete stuff; 
				num_items--; 
				return; 
			}
			else {
				Node* temp = head; 
				while (temp -> next -> data != value) {
					temp = temp -> next; 
					if (temp -> next == NULL) {
						return; 
					}
				}
				Node* something; 
				something = temp -> next; 
				temp -> next = temp -> next -> next; 
				delete something; 
				num_items--; 
				return; 
			}
		}
	}; 
	
	T at (int index) {
		T thing; 
		if ((index >= num_items) || (index < 0)) {
			throw std::out_of_range("");
		}
		else {
			Node* ptr = head; 
			for (int i = 0; i < num_items; i++) {
				if (index == i) {
					thing = ptr -> data;
					return thing;  
				}
				else {
					ptr = ptr -> next; 
				}
			}
		}
	}; 
	
	
	int size() {
		return(num_items); 
	}; 
	
	void clear() {
		while(head != NULL) {
			Node *current = head;
			head = head->next;
			delete current;
			num_items--; 
		};
	}; 
	
	string toString() {
		if (head == NULL) {
			return ""; 
		}
		stringstream ss;
		for (Node* ptr = head; ptr != NULL; ptr = ptr -> next) {
			ss << ptr -> data << " "; 
		}
		string finalOutput = ss.str(); 
		ss.str(""); 
		finalOutput.erase(finalOutput.length() - 1, 1); 
		ss << finalOutput; 
		return ss.str(); 
	}; 
	
}; 