#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;

template<typename T>

void parse_instruction(string temp, LinkedList<T>* LLptr) {
	string command, listString;
	T val;
	//T insertionNode;
	//int index, size;

	stringstream ss(temp);
	ss >> command;
	if (command == "insertHead") {
		ss >> val;
		LLptr->insertHead(val);
		cout << temp << endl;
	}
	else if (command == "insertTail") {
		ss >> val;
		LLptr->insertTail(val);
		cout << temp << endl;
	}
}

int main(int argc, char* argv[]) {

	ifstream in(argv[1]);
	ofstream out(argv[2]);

	string temp;
	string isString;
	LinkedList<int>* iLL = NULL;
	LinkedList<string>* sLL = NULL;

	getline(in, temp);

	if (temp == "INT") {
		isString = "INT";
		iLL = new LinkedList<int>();
		cout << endl << "INT[INT]" << endl;
	}
	else if (temp == "STRING") {
		isString = "STRING";
		sLL = new LinkedList<string>();
		cout << endl << "STRING[STRING]" << endl;
	}

	while (getline(in, temp)) {
		if (isString == "INT") {
			parse_instruction(temp, iLL);
		}
		else if (isString == "STRING") {
			parse_instruction(temp, sLL);
		}
	}

	if (iLL != NULL) {
		delete iLL;
		iLL = NULL;
	}
	else if (sLL != NULL) {
		delete sLL;
		sLL = NULL;
	}

	in.close();
	out.close();


	system("pause");
	return 0;

}