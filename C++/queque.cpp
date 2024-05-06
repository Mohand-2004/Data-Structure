// Queque Implementation using C++ Programming Language
// This Queque has 7 methodes :
// 1.lenght() => to return the number of elements in queque
// 2.MAX() => to return the largest element with num data type and the largest ascii value for another data types
// 3.MIN() => to return the smallest element with num data type and the smallest ascii value for another data types
// 4.enqueque() => to insert a new element in the end of the queque
// 5.dequeque() => to delete and return the first element in the queque
// 6.print() => to print all or some of the elements in queque
// 7.peek() => to get the current element
// 8.operator[] => to access any value by it's element - this methode is useful to loop on the queque elements

// Mohand Elsebaey


#include<iostream>
#include"linkedlist.cpp"
using namespace std;

template <typename DataType> class Queque{
    protected:
        Node<DataType> linkedlist;
    public:
        // function to get queque lenght
        int lenght(){
            return this->linkedlist.lenght();
        }

        // function to get the maximum element in the queque
        DataType MAX(){
            return this->linkedlist.MAX();
        }

        // function to get the minimum element in the queque
        DataType MIN(){
            return this->linkedlist.MIN();
        }

        // function to inseret a new element in the end of the queque
        void enqueque(DataType value){
            this->linkedlist.insert(value);
        }

        // function to delete and return the first element in queque
        DataType dequeque(){
            return this->linkedlist.pop(0);
        }

        // function to print the elements of the queque
        void print(int start = 0,int end = -1){
            this->linkedlist.print(start,end);
        }

        // function to get the current element
        DataType peek(){
            return this->linkedlist[0];
        }

        // operator overloading to an element from a a specific position
        DataType operator [](int index){
            return this->linkedlist[index];
        }
};