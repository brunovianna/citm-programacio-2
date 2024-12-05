#include <iostream>
#include <cassert>

using namespace std;

class DynamicArray {
private:
	int size = 0;
	int capacity;

	string* array;
public:
	DynamicArray() {
		capacity = 10;
		array = new string[capacity];
	}
	DynamicArray(int _c) {
		capacity = _c;
		array = new string[capacity];
	}
	DynamicArray(int _c, string* init, int init_size) {
		capacity = _c;
		size = init_size;
		//assert ("Initial size is greater than capacity", init_size < capacity);
		array = new string[capacity];
		for (int i = 0; i < init_size; i++) {
			array[i] = init[i];
		}
	}
	bool insert(string newElement, int position) {
		if (capacity <= size) {
			capacity *= 2;
		}
		string* newArray = new string[capacity];
		size++;
		int i;
		for (i = 0; i < position; i++) {
			newArray[i] = array[i];
		}
		cout << i << endl;
		newArray[i] = newElement;
		i++;
		while (i < size) {
			newArray[i] = array[i - 1];
			i++;
		}
		delete[] array;
		array = newArray;
		return true;


	}

	bool remove(int position) {
		if (position >= size || position < 0) {
			cout << "Posicio inexistent";
			return false;
		}
		string* newArray = new string[capacity];
		size--;

		for (int i = 0; i < position; i++)
		{
			newArray[i] = array[i];
		}
	
		for (int i = position; i < capacity - 1; i++)
		{
			newArray[i] = array[i + 1];
		}
		delete[] array;

		array = newArray;
		return true;


	}


	void print() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << ", ";
		}
		cout << endl;
	}
};


int main() {
	string start[10];

	DynamicArray a(10);

	a.insert("bli", 0);
	a.print();
	a.insert("blo", 0);
	a.print();
	a.insert("blu", 0);
	a.print();
	a.remove(-10);
	a.print();


}