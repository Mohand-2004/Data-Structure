# Queque Implementation using Python Programming Language
# This Queque has 7 methodes :
# 1.lenght() => to return the number of elements in queque
# 2.MAX() => to return the largest element with num data type and the largest ascii value for another data types
# 3.MIN() => to return the smallest element with num data type and the smallest ascii value for another data types
# 4.enqueque() => to insert a new element in the end of the queque
# 5.dequeque() => to delete and return the first element in the queque
# 6.print() => to print all or some of the elements in queque
# 7.peek() => to get the current element
# 8.operator[] => to access any value by it's element - this methode is useful to loop on the queque elements

# Mohand Elsebaey

from linkedlist import *

class Queque:
    def __init__(self):
        self.linkedlist = Node()

    #function to get queque lenght
    def lenght(self):
        return self.linkedlist.lenght
    
    # function to get the maximum element in the queque
    def MAX(self):
        return self.linkedlist.MAX()
    
    # function to get the minimum element in the queque
    def MIN(self):
        return self.linkedlist.MIN()
    
    # function to insert a new item to the quque
    def enqueque(self,value):
        self.linkedlist.insert(value)

    # function to delete an element from the end of the queque
    def dequeque(self):
        return self.linkedlist.pop(0)

    # function to print the elements of the queque
    def print(self,start = 0,end = -1):
        self.linkedlist.print_items(start,end)

    # function to get the current element
    def peek(self):
        return self.linkedlist[0]
    
    # operator overloading to an element from a a specific position
    def __getitem__(self,index):
        return self.linkedlist[index]