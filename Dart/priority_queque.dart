// Prority Queque Implementation using Dart Programming Language
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


import 'dart:io';
import 'linkedlist.dart';
class Item<DataType>{
  late DataType _value;
  bool _highPriority = false;
  Item({required DataType value,bool high = false}){
    _value = value;
    _highPriority = high;
  }
  DataType get value => _value;
  bool get highPriority => _highPriority;
}
class PriorityQueque<DataType>{
  Node<Item<DataType>> _linkedlist = Node();

  // function to get queque lenght
  int lenght(){
    return this._linkedlist.lenght;
  }
  // function to get the maximum element in the queque
  DataType MAX(){
    DataType max = this._linkedlist[0]!.value;
    // for(int i = 0;i<this._linkedlist.lenght;i++){
    //   if(_linkedlist[i]!.value! > max){
    //     max = this._linkedlist[i]!.value;
    //   }
    // }
    return max;
  }

  // function to get the minimum element in the queque
  DataType MIN(){
    DataType min = this._linkedlist[0]!.value;
    // for(int i = 0;i<this._linkedlist.lenght;i++){
    //   if(_linkedlist[i]!.value! < min){
    //     min = this._linkedlist[i]!.value;
    //   }
    // }
    return min;
  }

  // function to inseret a new element in the end of the queque
  void enqueue({required DataType value,bool high = false}){
    this._linkedlist.insert(value: Item(value: value,high: high));
  }

  // function to delete and return the first element in queque
  DataType dequeque(){
    for(int i = 0;i<this._linkedlist.lenght;i++){
      if(this._linkedlist[i]!.highPriority){
        return this._linkedlist.pop(i)!.value;
      }
    }
    return this._linkedlist.pop(0)!.value;
  }

  // function to print the elements of the queque
  void print({int start = 0,int end = -1}){
    if(end == -1){
      end = this._linkedlist.lenght;
    }
    stdout.write('[');
    for(int i = start;i<end;i++){
      stdout.write('${this._linkedlist[i]!.value},');
    }
    stdout.write(']');
  }

  // function to get the current element
  DataType peek(){
    for(int i = 0;i<this._linkedlist.lenght;i++){
      if(this._linkedlist[i]!.highPriority){
        return this._linkedlist[i]!.value;
      }
    }
    return this._linkedlist[0]!.value;
  }

  // operator overloading to an element from a a specific position
  DataType? operator [](int index){
    return this._linkedlist[index]?.value;
  }
}