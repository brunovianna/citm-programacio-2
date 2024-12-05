
#include <iostream>

using namespace std;

class Queue {
public:
    Queue() {
        _back = -1;
        _capacity = 10;
        _array = new int[_capacity];
        std::cout << "Queue constructed." << std::endl;
    }

    ~Queue() {
        delete[] _array;
        std::cout << "Queue destroyed." << std::endl;
    }

    void enqueue(int value) {
        if (_back + 1 == _capacity) {
            resize();
        }

        _back++;
        _array[_back] = value;
    }


    int dequeue() {
        if (empty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
        }
        int frontValue = _array[0];
        for (int i = 0; i < _back; ++i) {
            _array[i] = _array[i + 1];
        }
        _back--;
        return frontValue;
    }


    int size() const {
        return _back + 1;
    }


    bool empty() const {
        return _back == -1;
    }

    void print() {
        for (int i = 0; i < _back + 1; i++) {
            cout << _array[i] << " ";
        }
        cout << endl;
    }

private:
    int _back;
    int* _array;
    int _capacity;


    void resize() {
        int newCapacity = _capacity * 2;
        int* newArray = new int[newCapacity];


        for (int i = 0; i < _capacity; ++i) {
            newArray[i] = _array[i];
        }

        delete[] _array;
        _array = newArray;
        _capacity = newCapacity;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Initial queue:" << std::endl;
    q.print();

    q.dequeue();
    std::cout << "After dequeuing one element:" << std::endl;
    q.print();

    q.enqueue(40);
    q.enqueue(50);
    std::cout << "After adding two more elements:" << std::endl;
    q.print();
}
