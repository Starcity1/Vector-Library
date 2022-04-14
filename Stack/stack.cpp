#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    int position;
    T* Stack_Array;
    
    void Extend_Stack() {
        T *new_stack;
        new_stack = new T[position * 2];
        for (int index = 0; index < position; index++) {
            new_stack[index] = Stack_Array[index];
        }

        //Delete the contents of the array and set the new pointers to the new allocated space. Then delete:
        delete[] Stack_Array;
        Stack_Array = new_stack;
        new_stack = nullptr;
        return;
    }

public:
    Stack() {
        Stack_Array = new T[1];
        position = 0;
    }
    int size() {
        return position;
    }
    void push(T value) {
        if (position >= (sizeof(Stack_Array)/sizeof(Stack_Array[0]))) {
            Extend_Stack();
        }
        cout << "New size of stack: " << sizeof(Stack_Array) / sizeof(T) << endl;
        Stack_Array[position] = value;
        position++;
    }
    void pull() {
        if (position == 0) {
            cout << "Error: The stack is empty." << endl; 
            return;
        }
        Stack_Array[position] = 0;
        position --;
    }
    void print() {
        if (position == 0) {
            cout << "Error: The stack is empty." << endl;
            return;
        }
        for(int index = 0; index < position; index++) {
            if(index == position - 1) {
                cout << Stack_Array[index];
                break;
                }
            cout << Stack_Array[index] << " -> ";
        }
        cout << endl;
    }
};
