# Ordered Linked List

As we have learned in class, Linked-lists are good for a dynamic collection of
items where the collection is constantly being added to and removed from.
In this assignment you will create a linked list class that keeps the items in
sorted order.  The class will be templated so that is can be used with any of
the built-in datatypes or a custom class that implements the necessary operators.

We will use several built-in types as well as a custom MemberDO to test the
OrderedLinkedList implementation.  A MemberDO is an object which could be used
for tracking Membership in a club like the ACM (Association of Computing Machinery)
and tracking how much money each member currently owes for their dues.
The information for each Member includes an Identification Number, Last Name,
First Initial, and Yearly Dues.

## Goals:
The purpose of this project is to continue working with C++ classes,
practice working with templates, and understand and implement the concepts of a
linked list data structure.

## Requirements:
Code construction can be divided into two primary tasks:

### 1. **Ordered Linked List class**

This class creates and manages the ordered linked list using template syntax.
The list should rely upon the templated class having implemented the "<" and "=="
operators.  The use of these operators is described below. When items are inserted
into the list they are inserted in "sorted order" as defined by the "<" operator.
Items are retreived by their position in the list.  Their position in the list
can be determined using the find method which uses the "==" operator to determine
if the current item is the item being found.  Similarly the remove method finds
the first occurrence of the item as defined by the "==" operator and removes it
from the list. Finally the "<<" operator should call the "<<" operator on the item
being stored in the list and add additional formating described below.

At a minimum you must implement the following public methods:

+ OrderedLinkedList(); initializes the list to an empty state.
+ OrderedLinkedList(const OrderedLinkedList& other); creates a deep-copy of the other list.
+ OrderedLinkedList<Type>& operator=(const OrderedLinkedList<Type>& other); creates a deep-copy of the other list and cleans up any previously used memory.
+ ~OrderedLinkedList(); cleans up any previously used memory.
+ int size() const; returns the current number of items in the list.
+ bool empty() const; returns true if the list is currently empty (i.e. the size is 0)
+ Type get(int pos) const; returns the item at the specified position in the list. Throws an out_of_range_exception if the pos is outside the bounds of the list.
+ Type getFirst() const; returns the first item in the list. Throws an out_of_range exception if the list is empty
+ Type getLast() const; returns the last item in the list. Throws an out_of_range exception if the list is empty
+ void insert(const Type&); inserts the item into the list in the correct order.
+ int find(const Type&) const; returns the position of the item in the list if it is found or -1 if the item is not in the list.  Use the "==" operator to determine if the item is the one being found.
+ void remove(const Type&); Removes the item from the list.  If the item is not in the list this method has no effect.  Use the "==" operator to determine if the item is the one to be removed.
+ void clear(); deletes the entire list and resets it to an empty state.
+ OrderedLinkedList<Type> everyOtherOdd(); returns a new list that contains every other item in the list starting with the first item (index 0).
+ OrderedLinkedList<Type> everyOtherEven(); returns a new list that contains every other item in the list starting with the second item (index 1).
+ friend std::ostream& operator<< <>(std::ostream&, const OrderedLinkedList<Type>& list); Outputs the items in the list formated as item1->item2->...->itemn.  For example. if the list is 1,2,3,4. This method outputs 1->2->3->4


**As noted in the above specifications, the ordered linked list methods should be implemented such that any class which implements the "<", "==", and "<<" operators can be used.**


### 2. **MemberDO class**

Most of the MemberDO class has been implemented for you as it was just simple
getters and setters.  However, you will need to implement any necessary operators
for the class to be used in the OrderedLinkedList.  Specifically, you should use
the "key" value when comparing and printing MemberDO objects.

The key represents the unique ID number of the club member and will be used exclusively to locate nodes in the implementation of the linked list methods.

