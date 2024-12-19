#include <iostream>
using namespace std;

struct Node {
	string name;
	Node* next;
};

class SingleLinkedList {
private:
	int size;




public:
	Node* head;
	SingleLinkedList()  {
    	head = nullptr;
    	size = 0;

	}

	void insert(string value) {
    	Node* newNode = new Node;
    	newNode->name = value;
    	newNode->next = nullptr;

    	if (head == nullptr) {
        	head = newNode;
    	}
    	else {
        	newNode->next = head;
        	head = newNode;
    	}


    	size++;
	}

	// Function to print the contents of the list
	void print() {
    	Node* current = head;
    	while (current != nullptr) {
        	cout << current->name << " ";
        	current = current->next;
    	}
    	cout << endl;
	}

	void recursivePrint(Node * n) {
   	 
    	if (n==nullptr) {
        	cout << endl;
        	return;
    	}
   	 
    	cout << n->name << " ";
    	recursivePrint(n->next);

	}


	int getSize() {
    	return size;
	}
};

int main() {
	SingleLinkedList list;
	list.insert("tuna");
	list.insert("oli");
	list.insert("mika");
	list.insert("jukka");
	list.insert("tuomo");
	list.print(); // Output: 3 2 1
	list.recursivePrint(list.head);
	cout << "Size: " << list.getSize() << endl; // Output: Size: 3
	return 0;
}
