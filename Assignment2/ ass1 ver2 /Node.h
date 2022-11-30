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

#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node
{
public:
    // constructor
    Node(Student);
    
    // destructor
    ~Node();
    
    // set next node
    void setNext(Node*);
    
    // get next node
    Node *getNext();
    
    // get studetn data
    Student getData();
private:
    Student data;
    Node *next;
};

#endif
