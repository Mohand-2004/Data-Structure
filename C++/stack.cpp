// Stack Implementation using C++ Programming Language
// This Stack has 8 methodes :
// 1.lenght() => to return the number of elements in Stack
// 2.MAX() => to return the largest element with num data type and the largest ascii value for another data types
// 3.MIN() => to return the smallest element with num data type and the smallest ascii value for another data types
// 4.push() => to insert a new element in the end of the Stack
// 5.pop() => to delete and return the last element in the Stack
// 6.print() => to print all or some of the elements in Stack
// 7.peek() => to get the current element
// 8.operator[] => to access any value by it's element - this methode is useful to loop on the Stack elements

// Mohand Elsebaey

#include<iostream>
#include"linkedlist.cpp"
using namespace std;

template <typename DataType> class Stack{
    private:
        Node<DataType> linkedlist;
    public:
        // function to get stack lenght
        int lenght(){
            return this->linkedlist.lenght();
        }

        // function to get the maximum element in the stack
        DataType MAX(){
            return this->linkedlist.MAX();
        }

        // function to get the minimum element in the stack
        DataType MIN(){
            return this->linkedlist.MIN();
        }

        // function to insert a new value to the stack
        void push(DataType value){
            this->linkedlist.insert(value);
        }

        // function to delete and return the last value of the stack
        DataType pop(){
            if(this->linkedlist.lenght() == 0){
                cout<<"Stack Under Flow !";
            }
            else{
                return this->linkedlist.pop();
            }
        }

        // function to print all or some of the elements in Stack
        void print(int start = 0,int end = -1){
            if(this->linkedlist.lenght() == 0){
                cout<<"Stack Under Flow !";
            }
            else{
                this->linkedlist.print(start,end);
            }
        }

        // function to get the current element
        DataType peek(){
            if(this->linkedlist.lenght() == 0){
                cout<<"Stack Under Flow !";
            }
            else{
                return this->linkedlist[this->linkedlist.lenght()-1];
            }
        }

        // operator overloading to an element from a a specific position
        DataType operator [](int index){
            return this->linkedlist[index];
        }
};