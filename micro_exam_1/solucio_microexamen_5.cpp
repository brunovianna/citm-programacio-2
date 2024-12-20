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
    SingleLinkedList() {
        head = nullptr;
        size = 0;

    }

    bool getContent(int index, string &result) {
        Node* current = head;
        if (index < size) {
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            result = current->name;
            return true;
        }
        //is index >= size, invalid request
        return false;
        
    }

    bool setContent(int index, const string content) {
        Node* current = head;
        if (index < size) {
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->name = content;
            return true;
        }
        //is index >= size, invalid request
        return false;

    }

    bool swapContent(int firstIndex, int secondIndex) {

        string firstName, secondName;
        if (!getContent(firstIndex, firstName)) {
            return false;
        }
        if (!getContent(secondIndex, secondName)) {
            return false;
        }
        if (!setContent(secondIndex, firstName)) {
            return false;
        }
        if (!setContent(firstIndex, secondName)) {
            return false;
        }

    }

    void shuffleContents() {
        for (int i = 0; i < size; i++)
        {
            int r = rand() % size;
            while (i == r)
            {
                r = rand() % size;
            }
            swapContent(i, r);
        }
    }


    void swapElement(int firstIndex, int secondIndex) {
        Node* beforeFirst,* first, *beforeSecond,* second, * tmp;

        first = head;
        beforeFirst = nullptr;
        for (int i = 0; i < firstIndex ; i++) {
            beforeFirst = first;
            first = first->next;
        }

        second = head;
        beforeSecond = nullptr;
        for (int i = 0; i < secondIndex; i++) {
            beforeSecond = second;
            second = second->next;
        }



        if (beforeFirst == nullptr)
        {
            head = second;
        } 
        else
        {
            beforeFirst->next = second;

        }

        if (beforeSecond == nullptr)
        
        {
            head = first;
        }
        else {
            beforeSecond->next = first;
        }


        tmp = second->next;
        second->next = first->next;
        first->next = tmp;


    }

    void shuffleElements() {
        for (int i = 0; i < size; i++)
        {
            int r = rand() % size;
            while (i == r) 
            {
                r = rand() % size;
            }
            swapElement(i,r);

        }

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

    void recursivePrint(Node* n) {

        if (n == nullptr) {
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
    srand(std::time(nullptr));

    

    SingleLinkedList list;
    list.insert("tuna");
    list.insert("oli");
    list.insert("mika");
    list.insert("jukka");
    list.insert("tuomo");
    list.print(); // Output: 3 2 1
    list.swapElement(1, 2);

    list.shuffleElements();
    list.print(); // Output: 3 2 1

    return 0;
}
