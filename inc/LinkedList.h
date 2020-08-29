#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream>
#include "MemberDO.h"

template <class Type>
struct Node
{
	Type data;
	Node *next;
};

template <class Type>
class OrderedLinkedList;

template <class Type>
std::ostream& operator<<(std::ostream&, const OrderedLinkedList<Type>& list);


template <class Type>
class OrderedLinkedList
{
protected:
    Node<Type>* front;
    Node<Type>* back;
    int count;

public:
	OrderedLinkedList();
	OrderedLinkedList(const OrderedLinkedList& other);
	OrderedLinkedList<Type>& operator=(const OrderedLinkedList<Type>& other);


	~OrderedLinkedList();

        int size() const;
        bool empty() const;
	Type get(int) const;
	Type getFirst() const;
	Type getLast() const;
	int insert(const Type&);
	int find(const Type&) const;
	void remove(const Type&);
        void clear();
        OrderedLinkedList<Type> everyOtherOdd();
        OrderedLinkedList<Type> everyOtherEven();
        friend std::ostream& operator<< <>(std::ostream&, const OrderedLinkedList<Type>& list);
};

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList()
{
    front = nullptr;
    back = nullptr;
    count = 0;
}

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList(const OrderedLinkedList<Type>& other)
{
    this->count = 0;
    front = nullptr;
    back = nullptr;
    int loopCounter = 0;

    auto currentNode = other.front;
    while(currentNode && loopCounter < other.count)                           //while current node exists and loopcounter is less than count, helps catch the back
    {
        Node <Type>* temp = new Node <Type>();
        temp->data = currentNode->data;
        this->insert(temp->data);

        currentNode = currentNode->next;
        loopCounter++;
    }

}

template <class Type>
OrderedLinkedList<Type>& OrderedLinkedList<Type>::operator=(const OrderedLinkedList& other)
{
    this->clear();
    this->count = 0;
    front = nullptr;
    back = nullptr;
    int loopCounter = 0;

    auto currentNode = other.front;
    while(currentNode && loopCounter < other.count)                           //while current node exists and loopcounter is less than count, helps catch the back
    {
        Node <Type>* temp = new Node <Type>();
        temp->data = currentNode->data;
        this->insert(temp->data);

        currentNode = currentNode->next;
        loopCounter++;
    }


    return *this;
}





template <class Type>
OrderedLinkedList<Type>::~OrderedLinkedList()
{
    Node<Type>* temp = front;        //copied the destructor from the learning activity, essentially the same as clear, but the deletion of the actual list object is handled abstractly
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class Type>
int OrderedLinkedList<Type>::size() const
{
return count;
}

template <class Type>
bool OrderedLinkedList<Type>::empty() const
{
if(count == 0)                    //checks if the size is 0
{
    return -1;                   //returns -1 indicating it is 0
}
else
    return false;

}

template <class Type>
Type OrderedLinkedList<Type>::get(int pos) const
{
    if (this->count == 0)
    {
        throw std::out_of_range("out_of_range error");
    }

    int currentNodeNum = 0;
    auto currentNode = front;

    if (pos >= count)
    {
        throw std::out_of_range("Item does not exist");
    }
    if (pos == 0 && count > 0)
    {
        return currentNode->data;
    }
    while(currentNodeNum < pos)
    {
        currentNodeNum++;
        currentNode = currentNode->next;
    }
    return currentNode->data;

}

template <class Type>
Type OrderedLinkedList<Type>::getFirst() const
{
    if (count == 0)
    {
        throw std::out_of_range("out_of_range error");            //catch if there is nothing in the LinkedList
    }
   else
    {
       return this->front->data;         //returns the front
    }
}

template <class Type>
Type OrderedLinkedList<Type>::getLast() const
{
    if (count == 0)
    {
        throw std::out_of_range("out_of_range error");                          //catches if there is nothing in the linked list
    }
    else
        {
            return this->back->data;                                  //returns back
        }

}

template <class Type>
int OrderedLinkedList<Type>::insert(const Type& item)
{
Node <Type>* temp = new Node <Type>();
    temp->data = item;                       //temp is now the item that we are going to be placing in our list

    if (!front)                                       //check if there is a front node, here !front means no front node
    {
        this->front = temp;
        this->back = temp;

    }
    /* else
    {
        temp->next = nullptr;
        back->next = temp;
        back = temp;
    } */

    else                                              //establishes that there is indeed data in this linked list
    {                                                  //program doesn't work as of now, implemented some basic stuff, working on sorting the linkedlist
        int flag = 0;                                 //creation of a flag, flag will be triggered if the linkedList is empty and will avoid the loop
        int loopFlag = 0;                             //creation of a flag, but for the while loop to avoid checking currentNode is less than
        int loopCounter = 1;
        auto currentNode = this->front;

        if (count == 1)
        {
            if (temp->data < currentNode->data)             //before beginning the loop,
            {
                temp->next = currentNode;                   //set temp's pointer to the front
                this->front = temp;                         //label temp as the front now
                flag = flag++;


            } else {
                this->front->next = temp;
                this->back = temp;
                temp->next = nullptr;
            }
        }
        //auto beforeNode = currentNode;

        if (flag == 0 && temp->data < this->front->data)
        {
            temp->next = this->front;
            this->front = temp;

            flag++;
        }

        while(loopCounter < this->count && flag == 0)                           //itterate throught the linkedlist
        {

           auto PastNode = currentNode;

            currentNode = currentNode->next;                       //change currentNode to the next position on the linkedList

            if (loopCounter == 1 && temp->data < PastNode->data)     //this piece of code may not be necessary after my if statement before the loop, left in just in case it would break the code
            {
                temp->next = PastNode;
                this->front = temp;
                break;
            }



            if (currentNode == NULL)                              //checks if the last entry in the linkedlist is null so we can label temp as the back
            {
                back->next = temp;
                this->back = temp;
                this->back->next = nullptr;                       //this loop is for catching when the data temp is being compared to is null, which means it is now the head
                break;

            }


            if (temp->data < currentNode->data)                    //if currentNode->next exists
            {

                temp->next = currentNode;                          //this loop sets temp if it catches the fact that it is lower than the data it is being compared to
                PastNode->next = temp;
                break;
            }
            //beforeNode = PastNode;

        }




        /*temp->next = nullptr;
        back->next = temp;
        back = temp; */
    }
    count++;
}


template <class Type>
int OrderedLinkedList<Type>::find(const Type& item) const
{
    Node <Type>* itemNode = new Node <Type>();
    auto currentNode = this->front;
    itemNode->data = item;
    int needle = 0;                               //setting the needle variable, will be returned once the loop is finished cycling through
    while(currentNode)                           //while current node exists
    {
        if (currentNode->data == itemNode->data)
        {
            return needle;                       //returns the position at which the item was found
        }
        currentNode = currentNode->next;        //cycle to the next item in the linkedlist
        needle++;                               //add one to the needle
    }
    return -1;

    return -2;
}

template <class Type>
void OrderedLinkedList<Type>::remove(const Type& item)
{
    if (this->count == 0)                //instant check to see if the list is empty
    {
        return;
    }
    int currentNodeNum = 0;
    auto currentNode = front;
    Node <Type>* temp = new Node <Type>();
    temp->data = item;

    if(this->front->data == temp->data)              //immediataely check if the front data is equal to temp that we created

    {
        front = front->next;
        delete currentNode;
        count--;
        if (count == 0)
        {
            this->front = nullptr;
            this->back = nullptr;
        }
        return;
    }
    while (currentNodeNum < count - 1)
    {
        currentNodeNum ++;
        auto pastNode = currentNode;
        currentNode = currentNode->next;
        if (currentNode->data == temp->data)                   //checks if the currentNod is equal to the argument passed into the function, will delete the node with same argument
        {
            if (currentNodeNum == count - 2)                   //redundant loop, left in in case anything breaks
            {
                auto toDelete = currentNode->next;
                currentNode->next = toDelete->next;
                auto backLL = currentNode;
                backLL->next = nullptr;
                this->back = backLL;
                delete toDelete;
                count--;
                return;
            }
            else
                    {                                            //this loop is where most stuff gets done, has a check inside if next is null
                    auto toDelete = pastNode->next;
                    currentNode = currentNode->next;
                    delete toDelete;
                    pastNode->next = currentNode;
                    count--;
                    if (currentNode == NULL)                    //checks if currentNode is NULL, will set pastNode as the back of the LinkedList
                        {
                            this->back = pastNode;
                            pastNode->next = NULL;
                        }
                    return;
                }

        }
    }


}

template <class Type>
void OrderedLinkedList<Type>::clear()
{
    Node<Type>* temp = front;
    while (front != nullptr)              //while the front does not equal null
    {
        temp = front;
        front = front->next;              //deleting that node
        delete temp;
    }
    count = 0;                            //set the count to 0
}


template <class Type>
OrderedLinkedList<Type> OrderedLinkedList<Type>::everyOtherOdd(){
OrderedLinkedList<Type> retVal;
    auto currentNode = this->front;
    int oddCounter = 0;                          //used to see if the node needs to be added to the oddList
    while(currentNode && oddCounter < this->count)                           //while current node exists
    {
        if (oddCounter == 0 || oddCounter % 2 == 0)                     //establishes the head
        {
            Node <Type>* temp = new Node <Type>();
            temp->data = currentNode->data;
            retVal.insert(temp->data);
        }
        currentNode = currentNode->next;
        oddCounter++;
    }


return retVal;
}

template <class Type>
OrderedLinkedList<Type> OrderedLinkedList<Type>::everyOtherEven(){
OrderedLinkedList<Type> retVal;
    auto currentNode = this->front;
    int evenCounter = 0;                          //used to see if the node needs to be added to the oddList
    while(currentNode && evenCounter < this->count)                           //while current node exists
    {
        if (evenCounter == 1 || evenCounter % 2 != 0)                     //establishes the head
        {
            Node <Type>* temp = new Node <Type>();
            temp->data = currentNode->data;
            retVal.insert(temp->data);
        }
        currentNode = currentNode->next;
        evenCounter++;
    }
return retVal;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const OrderedLinkedList<Type>& list)
{
    auto currentNode = list.front;
    while(currentNode)                           //while current node exists
    {
        out << currentNode->data;
        if (currentNode->next)                    //if currentNode->next exists
        {
            out << "->";
        }
        currentNode = currentNode->next;
    }
    return out;
}
#endif
