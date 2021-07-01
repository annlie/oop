//
//  Node.hpp
//  hw08
//
//  Created by Annlie Nguyen on 12/8/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>

struct Node {
    Node(int x = 0, Node* l = nullptr);
    int data;
    Node* next;
};

// listDisplay displays the data values in the list.
void listDisplay(const Node* headPtr, std::ostream& = std::cout) ;

// listLength returns the length of the list pointed to by headPtr.
int listLength(const Node* headPtr) ;

// listClear frees up all the nodes in a list, setting the head pointer to NULL.
void listClear(Node*& headPtr) ;

// listRemove removes from the list the node immediately after previousPtr
void listRemoveAfter(Node* previousPtr) ;

#endif /* Node_hpp */
