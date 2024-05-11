// LinkedList Implementation using C++ Programming Language
// This linkedlist has 11 methodes :
// 1.lenght() => to return the number of elements in linkedlist
// 2.MAX() => to return the largest element with num data type and the largest ascii value for another data types
// 3.MIN() => to return the smallest element with num data type and the smallest ascii value for another data types
// 4.insert() => to insert a new element in the linkedlist in any place
// 5.print() => to print all or some of the elements in linkedlist
// 6.pop() => to delete an element from any place and return the deleted element value
// 7.remove() => to delete an element by it's value
// 8.update() => to update any element in the linkedlist
// 9.swap() => to swap any two elements in the linkedlist
// 10.copy() => to copy the elements of the linkedlist in a new linkedlist 
// 11.operator[] => to access any value by it's element - this methode is useful to loop on the linkedlist elements
// 12.operator= => to assign a list to the linkedlist easly
// 13.operator+ to Concatenate a new linkedlist to this linkedlist
// 14.indexof() => to get the index of a speceific value


// Mohand Elsebaey

#include<iostream>
using namespace std;


// linked List Implementation with premitive DataTypes
template <typename DataType> class Node{
    private:
        // the value which will be stored in the node
        DataType item;
        // pointer to accsses next node
        Node* next = NULL;
        // this attribute to accsess linkedlist lenght
        int len = 0;
        // A flag to indicate if linkedlist is empty or not
        bool isEmpty = true;
    public:
        // getter function to private attribute (len)
        int lenght(){
            return this->len;
        }
        // function to get the largest element in linkedlist
        DataType MAX(){
            if(this->isEmpty){
                cout<<"Linked List Is Empty !";
            }
            else{
                Node* current = this;
                DataType largest = this->item;
                while(current != NULL){
                    if(current->item >= largest){
                        largest = current->item;
                    }
                    current = current->next;
                }
                return largest;
            }
        }
        // function to get the smallest element in linkedlist
        DataType MIN(){
            if(this->isEmpty){
                cout<<"Linked List Is Empty !";
            }
            else{
                Node* current = this;
                DataType smallest = this->item;
                while(current != NULL){
                    if(current->item <= smallest){
                        smallest = current->item;
                    }
                    current = current->next;
                }
                return smallest;
            }
        }
        // function to insert a new value to linkedlist
        void insert(DataType value,int index = -1){
            // set index by default to linkedlist lenght
            if(index == -1){
                index = this->len;
            }
            // check if index is in linkedlist range
            if(index <= this->len && index >= 0){
                // check if linked list is empty
                if(this->isEmpty){
                    this->item = value;
                    this->isEmpty = false;
                }
                else{
                    // insert begganing case
                    if(index == 0){
                        Node* second = new Node();
                        second->item = this->item;
                        Node* third = this->next;
                        this->item = value;
                        this->next = second;
                        second->next = third;
                    }

                    // insert in the end and this is the default case
                    else if(index == this->len){
                        Node* node = new Node();
                        node->item = value;
                        Node* last = this;
                        while(last->next != NULL){
                            last = last->next;
                        }
                        last->next = node;
                    }
                    // insert at middle (between two node) and this the general case
                    else{
                        Node* node = new Node();
                        node->item = value;
                        Node* start = this;
                        Node* end = this->next;
                        for(int i = 0;i<index-1;i++){
                            start = start->next;
                            end = end->next;
                        }
                        start->next = node;
                        node->next = end;
                    }
                }
                // increment lenght
                this->len++;
            }
            // handle index out of range error
            else{
                cout<<"Error,out of range index !";
            }
        }
        // print all the elements of the linkedlist by defualt
        // print a part of the elements between start and end
        void print(int start = 0,int end = -1){
            // set end to default value 
            if(end == -1){
                end = this->len;
            }
            // check if linked list is Empty
            if(this->isEmpty){
                cout<<"Linked List Is Empty !";
            }
            else{
                // check if start and end are in range
                if(start >= this->len || end > this->len || start < 0 || end < 0){
                    cout<<"Error , Out of range index !";
                }
                // assert that end is bigger than start
                else if(end < start){
                    cout<<"Error , End index must be bigger than Start index !";
                }
                else{
                    Node* current = this;
                    // move the start node to the target position
                    for(int i = 0;i<start;i++){
                    current = current->next;
                    }
                    cout<<'[';
                    // print nodes from start node to last node 
                    for(int i = start;i<end;i++){
                        cout<<current->item<<',';
                        current = current->next;
                    }
                    cout<<']';
                }
            }
        }
        // delete a specific element by index and return the deleted element
        DataType pop(int index = -1){
            // set index to default value
            if(index == -1){
            index = this->len-1;
            }
            // check if index is in linkedlist range
            if(index >= this->len || index < 0){
                // handle out of range index
                cout<<"Error , Out Of Range Index !\n";
            }
            else{
                // decrement linkedlist lenght
                this->len--;

                // delete the only node in linkedlistt
                if(this->len == 0){
                    this->isEmpty = true;
                    return this->item;
                }
                else{
                    // set the index to linkedlist lenght
                    // to pop the last element by default
                    if(index == -1){
                        index = this->len;
                    }

                    // delete from beggining
                    if(index == 0){
                        DataType deletedValue = this->item;
                        this->item = next->item;
                        Node* newNext = this->next->next;
                        delete this->next;
                        this->next = newNext;
                        return deletedValue;
                    }

                    // delete an element between 2 elements (from middle)
                    else{
                        Node* targetPrevious = this;
                        Node* target = this;
                        Node* targetNext = this;
                        for(int i = 0;i<index-1;i++){
                            targetPrevious = targetPrevious->next;
                            target = target->next;
                            targetNext = targetNext->next;
                        }
                        target = target->next;
                        DataType deletedValue = target->item;
                        targetNext = targetNext->next->next;
                        delete target;
                        targetPrevious->next = targetNext;
                        return deletedValue;
                    }
                }
            }
        }
        // delete element by value
        void remove(DataType value){
            // remove the first node
            if(value == this->item){
                // remove the only node in linkedlistt
                if(this->len == 1){
                    this->isEmpty = true;
                }
                else{
                    this->item = next->item;
                    Node* newNext = this->next->next;
                    delete this->next;
                    this->next = newNext;
                }
                // decrement the linkedlist lenght
                this->len--;
            }
            
            // remove a node from middle by value
            else{
                Node* targetPrevious = this;
                Node* target = this->next;
                Node* targetNext = this->next->next;
                while(target->item != value){
                    targetPrevious = targetPrevious->next;
                    target = target->next;
                    targetNext = targetNext->next;
                    if(targetNext == NULL){
                        cout<<"There is no element has this value !\n";
                        return ;
                    }
                }
                targetPrevious->next = targetNext;
                delete target;
                // decrement the linkedlist lenght
                this->len--;
            }
        }

        // update a node item
        void update(int index,DataType value){
            // check if index in linkedlist range
            if(index >= this->len || index < 0){
                // handle out of range index
                cout<<"Error , Out Of Range Index !\n";
            }
            else{
                Node* target = this;
                for(int i = 0;i<index;i++){
                    target = target->next;
                }
                target->item = value;
            }
        }

        // swap the values of two nodes
        void swap(int index1,int index2){
            // check if index in linkedlist range
            if(index1 >= this->len || index2 >= this->len || index1 < 0 || index2 < 0){
                // handle out of range index
                cout<<"Error , Out Of Range Index !\n";
            }
            else{
                Node* target1 = this,*target2 = this;
                // move the first node to the target position
                for(int i = 0;i<index1;i++){
                    target1 = target1->next;
                }
                // move the second node to the target position
                for(int i = 0;i<index2;i++){
                    target2 = target2->next;
                }
                // swap the values of the two nodes
                DataType item1 = target1->item,item2 = target2->item;
                target1->item = item2;
                target2->item = item1;
            }
        }

        // index_of function to get an index of a specific value
        int index_of(DataType value){
            // check if linkedlist isn't Empty
            if(this->isEmpty){
                cout<<"Linked List Is Empty !";
            }
            else{
                Node* current = this;
                for(int i = 0;i<this->len;i++){
                    if(current->item == value){
                        return i;
                    }
                    else{
                        current = current->next;
                    }
                }
                cout<<"Error , this value isn't exist in the linkedlist";
            }
        }

        // return value by it's node index
        // this methode can be used if you want to loop on the linkedlist items
        // this methode is useful when linkedlist items is objects to accsess items methods 
        DataType operator [](int index){
            // check if index in linkedlist range
            if(index >= this->len || index < 0){
                // handle out of range index
                cout<<"Error , Out Of Range Index !\n";
            }
            else{
                Node* target = this;
                for(int i = 0;i<index;i++){
                    target = target->next;
                }
                return target->item;
            }
        }

        // a function to return a copy of the linkedlist
        Node<DataType> copy(){
            Node<DataType> copy;
            Node* current = this;
            while(current != NULL){
                copy.insert(current->item);
                current = current->next;
            }
            return copy;
        }

        // operator overloading to Concatenate a new linkedlist to this linkedlist
        Node<DataType> operator +(Node<DataType> list){
            Node<DataType> origin;
            Node* current = this;
            // add the elements of the linkedlist in the origin 
            while(current != NULL){
                origin.insert(current->item);
                current = current->next;
            }
            // add the elements of the other linkedlist in the origin
            for(int i = 0;i<list.lenght();i++){
                origin.insert(list[i]);
            }
            return origin;
        }

        // operator overloading to assign an array easliy to our linkedlist
        void operator =(DataType array[]){
            int arrayLenght = sizeof(array)/sizeof(array[0]);
            for(int i = 0;i<arrayLenght;i++){
                this->insert(array[i]);
            }
        }

};