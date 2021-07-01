//
//  Node.cpp
//  hw08
//
//  Created by Annlie Nguyen on 12/8/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Node.hpp"
using namespace std;

Node::Node(int x, Node* l) : data(x), next(l) {}

void listDisplay(const Node* p, ostream& os) {
    while (p) {
        os << p->data << ' ';
        p = p->next;
    }
    os << endl;
}

int listLength(const Node* p) {
    int length = 0;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

void listClear(Node*& p) {
    while (p) {
        Node *temp = p->next;
        delete p;
        p = temp;
    }
}

Node* listFindLast(Node* p) {
    if (p)
        while (p->next) p = p->next;
    return p;
}

void listRemoveAfter(Node* previousPtr) {
    Node* removePtr = previousPtr->next;
    previousPtr->next = removePtr->next;
    delete removePtr;
}
