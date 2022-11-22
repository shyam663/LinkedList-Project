/*
* Title: Project 2 Recursive Linked List.cpp
*Abstract: Implement linked list
*Author: Shyam Patel
*Email: ShyPatel@csumb.edu
*Estimate: 3 days
*Date: 5/7/2020
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;


/*** Implement these functions IN ORDER*/
// implement these two first
bool Node::hasNext() const {  
    return myNext != nullptr;
}


bool LinkedList::empty() const {  
    return myFirst == nullptr;
}


// then these two
void Node::display() const {
    cout << myData << " ";
    if (hasNext())
        myNext->display();
}


void LinkedList::display() const {  
    if (empty())
        cout << "Empty!" << endl;
    else {
        myFirst->display();
        cout << endl;
    }
}


// then these two
// only append if this is the last node
// otherwise, recurse
void Node::append(int data) {
    if (hasNext())
        myNext->append(data);
    // append if this is the last node
    else {
        Node *newNode = new Node(data);
        newNode->myNext = nullptr;
        myNext = newNode;
    }

}


void LinkedList::append(int data) {  
    // this won't work after the first time! 
    if (empty()) {
        myFirst = new Node(data);
    }
    else
        myFirst->append(data);
}


// then these two
bool Node::search(int data) const {  
    if (myData == data)
        return true;
    else {
        if (hasNext())
            return myNext->search(data);
        else
            return false;
    }
}


bool LinkedList::search(int data) const { 
    if (empty()) 
        return false;
    else
        return myFirst->search(data);
}

// then these two
bool Node::insertAfter(int oldData, int newData) {  
    // insert the node after the current node
    if (myData == oldData) {
        Node *newNode = new Node(newData);
        newNode->myNext = myNext;
        myNext = newNode;
        return true;
    }
    else {
        if (hasNext()) {
            return myNext->insertAfter(oldData, newData);
        }
        else
            return false;
    }
}


bool LinkedList::insertAfter(int oldData, int newData) {  
    if (empty()) 
        return false;
    else
        return myFirst->insertAfter(oldData, newData);
}


// then these two
bool Node::removeNext(int data) {  
    if (hasNext()) {
        // delete the next node
        if (myNext->myData == data) {
            Node *temp = myNext;
            myNext = myNext->myNext;
            delete temp;
            return true;
        }
        else
            return myNext->removeNext(data);
    }
    else 
        return false;
}


bool LinkedList::remove(int data) {  
    if (empty()) 
        return false;
    else {
        // delete the first node
        if (myFirst->getData() == data) {
            Node *temp = myFirst;
            myFirst = myFirst->getNext();
            delete temp;
            return true;
        }
        else
            return myFirst->removeNext(data);
    }
}

// then these two
Node::~Node() {
}

// recursively deletes a linked list starting from current
void deleteList(Node *current) {
    if (current == nullptr)
        return;

    deleteList(current->getNext());
    delete current;
}

LinkedList::~LinkedList() {
    if (!empty()) {
        deleteList(myFirst);
    }
}

// then these two
Node::Node(const Node & source) {
    myData = source.getData();
    if (source.hasNext()) {
        myNext = new Node(*(source.myNext));
    }
}

LinkedList::LinkedList(const LinkedList & source) {
    if (source.empty()) 
        myFirst = nullptr;
    else {
        myFirst = new Node(*(source.myFirst));
    }
}


// then this one
LinkedList LinkedList::operator=(const LinkedList & source) {  
    if(this == &source)
        return *this;
    if (source.empty()) 
        myFirst = nullptr;
    else {
        myFirst = new Node(*(source.myFirst));
    }
    return *this;
}

/*** Implement the functions above, shouldn't need to change anything below,
but look at this for good examples!*/
Node::Node(int data) {  
    myData = data;
    myNext = nullptr;
}


void Node::setNext(Node * next) {  
    myNext = next;
}

LinkedList::LinkedList() {  
    myFirst = nullptr;
}

