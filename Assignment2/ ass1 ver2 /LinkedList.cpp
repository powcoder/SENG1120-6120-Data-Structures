https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
//Course: SENG1120
//Coded by: Zemu Zhang
//Student ID: 3310315


#include "LinkedList.h"

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
};

LinkedList::~LinkedList(){
    Node* t;

    while(head)
    {
        t = head;
        head = head->getNext();

        delete t;
    }
};

// add student to tail
void LinkedList::addToTail(Student student_){
    // create a new student and node
    Student *newStudent = new Student(student_.get_name(), student_.get_score());
    Node *dataNode = new Node(*newStudent);
    
    // head has nothing, add to head and tail
    if (head == NULL){
        head = dataNode;
        tail = dataNode;
    } else {
        // add to tail
        tail->setNext(dataNode);
        tail = dataNode;
    }
}

// remove student with the given name
void LinkedList::remove(string name){
    // list has nothing, return
    if (getHead() == NULL){
        return;
    }
    Node *oldNode, *currNode;
    // found at head
    while (head->getData().get_name().compare(name) == 0){
        oldNode = head;
        head = head->getNext();
        delete oldNode;
    }
    // list has nothing, return
    if (getHead() == NULL){
        return;
    }
    // might in list
    currNode = getHead();
    while (currNode->getNext() != NULL){
        // use while to detect hence remove adjacent data with same name
        while (currNode->getNext()->getData().get_name().compare(name) == 0){
            oldNode = currNode->getNext();
            currNode->setNext(oldNode->getNext());
            delete oldNode;
        }
        currNode = currNode->getNext();
    }
}

// return the average score of students in the list
double LinkedList::calcAverage(){
    int counter = 0;
    double sum = 0;
    Node *currNode = getHead();
    while (currNode != NULL) {
        sum += currNode->getData().get_score();
        counter++;
        currNode = currNode->getNext();
    }
    return sum / counter;
}

// return the number of students in the list with given name
int LinkedList::count(string name){
    int counter = 0;
    Node *currNode = getHead();
    while (currNode != NULL) {
        if (currNode->getData().get_name().compare(name) == 0){
            counter++;
        }
        currNode = currNode->getNext();
    }
    return counter;
}

// sort the list
// this question is extremely difficult so the code might be a bit ugly
void LinkedList::order(){
    // find the smallest and swap to head
    Node *currLoop, *curr, *smallestPrev, *temp;
    // find the smallest excluding head
    curr = getHead();
    smallestPrev = getHead();
    while (curr->getNext() != NULL) {
        if (curr->getNext()->getData().get_name().compare(smallestPrev->getNext()->getData().get_name()) < 0){
            smallestPrev = curr;
        }
        curr = curr->getNext();
    }
    // compare to head, if smaller then swap
    if (smallestPrev->getNext()->getData().get_name().compare(getHead()->getData().get_name()) < 0){
        temp = getHead();
        head = smallestPrev->getNext();
        smallestPrev->setNext(temp);
        temp = temp->getNext();
        smallestPrev->getNext()->setNext(getHead()->getNext());
        getHead()->setNext(temp);
    }
    // head is sorted, then sort all the rest
    currLoop = getHead();
    while (currLoop->getNext() != NULL) {
        // find the smallest excluding currLoop's next
        curr = currLoop;
        smallestPrev = currLoop;
        while (curr->getNext() != NULL){
            if (curr->getNext()->getData().get_name().compare(smallestPrev->getNext()->getData().get_name()) < 0){
                smallestPrev = curr;
            }
            curr = curr->getNext();
        }
        // compare to currLoop's next, if smaller then swap
        if (smallestPrev->getNext()->getData().get_name().compare(currLoop->getNext()->getData().get_name()) < 0){
            temp = currLoop->getNext();
            currLoop->setNext(smallestPrev->getNext());
            smallestPrev->setNext(temp);
            temp = temp->getNext();
            smallestPrev->getNext()->setNext(currLoop->getNext()->getNext());
            currLoop->getNext()->setNext(temp);
        }
        currLoop = currLoop->getNext();
    }
}

Node *LinkedList::getHead(){
    return head;
}

Node *LinkedList::getTail(){
    return tail;
}

// print the list
ostream& operator <<(ostream& out, LinkedList &list)
{
    Node *studentNode = list.getHead();
    while (studentNode != NULL) {
        out << studentNode->getData() << " ";
        studentNode = studentNode->getNext();
    }
    return out;
}

// concatenate two lists
LinkedList& operator +=(LinkedList& firstList, LinkedList& secondList){
    Node *studentNode = secondList.getHead();
    while (studentNode != NULL){
        firstList.addToTail(studentNode->getData());
        studentNode = studentNode->getNext();
    }
    return firstList;
}
