// Queque Implementation using Dart Programming Language
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

import 'linkedlist.dart';


class Queque<DataType>{
  Node<DataType> _linkedlist = Node();
  
  // function to get queque lenght
  int lenght(){
    return this._linkedlist.lenght;
  }

  // function to get the maximum element in the queque
  DataType? MAX(){
    return this._linkedlist.MAX();
  }

  // function to get the minimum element in the queque
  DataType? MIN(){
    return this._linkedlist.MIN();
  }

  // function to insert a new item to the quque
  void enqueque(DataType value){
    this._linkedlist.insert(value: value);
  }

  // function to delete an element from the end of the queque
  DataType? dequeue(){
    return this._linkedlist.pop(0);
  }

  // function to print the elements of the queque
  void print({int start = 0,int end = -1}){
    this._linkedlist.print_items(start: start,end: end);
  }

  // function to get the current element
  DataType? peek(){
    return this._linkedlist[0];
  }

  // operator overloading to an element from a a specific position
  DataType? operator [](int index){
    return this._linkedlist[index];
  }
}
void main(){}