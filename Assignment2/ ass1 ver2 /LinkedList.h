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

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Student.h"
#include "Node.h"

class LinkedList
{
public:
    // Constructor
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // getters
    Node *getHead();
    Node *getTail();
    
    // add student to tail
    void addToTail(Student student);
    
    // remove student with the given name
    void remove(string);
    
    // return the average score of students in the list
    double calcAverage();
    
    // return the number of students in the list with given name
    int count(string);
    
    // sort the list
    void order();
    
private:
    // head and tail
    Node *head;
    Node *tail;
};
ostream& operator <<(ostream&, LinkedList&);
LinkedList& operator +=(LinkedList&, LinkedList&);



#endif 
