#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using Lmao = int;

struct AIEngineer {
	int iq = 130;
	string title = "Senior";
	string school = "Swinburne";
};

struct SinglyLinkedList {
	string data;	// the data type string here is just an example
	SinglyLinkedList* nextNode;

	SinglyLinkedList(string& aData, SinglyLinkedList* aNode = nullptr)
		: data(aData), nextNode(aNode) { }

	// R-value constructor
	SinglyLinkedList(string&& aData, SinglyLinkedList* aNode = nullptr)
		//: data(move(aData)), nextNode(aNode) {}
		: data(aData), nextNode(aNode) {
	}
};

void printRecursive(SinglyLinkedList* next) {
	if (next == nullptr) {
		cout << "END." << endl;
		return;
	}

	cout << next->data << endl;
	printRecursive(next->nextNode);
}

int main() {
	AIEngineer me;
	cout << me.school << endl;

	string lmao = "Ec";
	string lmao2 = "Bill";

	SinglyLinkedList tail(lmao);
	SinglyLinkedList* tail_ptr = &tail;
	SinglyLinkedList genesis(lmao2, tail_ptr);
	SinglyLinkedList* genesis_ptr = &genesis;

	// R-values:
	SinglyLinkedList third("alice");
	SinglyLinkedList* third_ptr = &third;
	SinglyLinkedList second("bob", third_ptr);
	SinglyLinkedList* second_ptr = &second;
	SinglyLinkedList first("bill", second_ptr);
	SinglyLinkedList* first_ptr = &first;

	SinglyLinkedList one("a");
	SinglyLinkedList two("b", &one);

	int a = 10;
	Lmao b = 20;

	cout << a + b << endl;

	//printRecursive(genesis_ptr);
	printRecursive(first_ptr);

	return 0;
}