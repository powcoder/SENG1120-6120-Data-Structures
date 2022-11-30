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

#include "Node.h"

Node::Node(Student data_){
    data = data_;
    next = NULL;
}

Node::~Node(){}

void Node::setNext(Node *next_){
    next = next_;
}

Node *Node::getNext(){
    return next;
}

Student Node::getData(){
    return data;
}
