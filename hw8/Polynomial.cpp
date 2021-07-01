//
//  Polynomial.cpp
//  hw08
//
//  Created by Annlie Nguyen on 12/8/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Polynomial.hpp"
#include "Node.hpp"
using namespace std;


ostream& operator<<(ostream& os, const Polynomial& rhs) {
    if (rhs.degree == 0 && rhs.head->data == 0
        && rhs.head->next == nullptr) { // zero polynomial
        os << '0' << endl;
        return os;
    }
    
    Node* holder = rhs.head->next; //constant term
    double currExp = rhs.degree;
    
    while (currExp != -1) {
        for (double i = currExp; i != 0; i--) {
            holder = holder->next;
        }
        if (currExp == 0) { //constant term
            os << holder->data << endl;
        } else if (holder->data == 1) { //no coefficient for x
            if (currExp == 1) { os << "x + "; }
            else { os << "x^" << currExp << " + "; }
        } else if (holder->data != 0) {
            if (currExp == 1) { os << holder->data << "x + "; }
            else { os << holder->data << "x^" << currExp << " + "; }
        }
        holder = rhs.head->next;
        --currExp;
    }
    
    return os;
} //end output operator
    
bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
    if (listLength(lhs.head->next) != listLength(rhs.head->next)
        || lhs.degree != rhs.degree) {
        return false;
    }
    Node* holder = lhs.head->next;
    Node* rhsHolder = rhs.head->next;
    size_t size = listLength(rhs.head->next);
    for (size_t i = size; i != 1; --i) {
        if (holder->data != rhsHolder->data) { return false; }
        holder = holder->next;
        rhsHolder = rhsHolder->next;
    }
    
    return true;
} //end == operator
    
Polynomial::Polynomial(vector<int> vec) {
    head = new Node(); //not part of actual polynomial, just the head
    Node* holder = head;
    size_t size = vec.size() - 1;
    degree = vec.size() - 1;
    for (size_t i = size; i != -1; --i) {
        holder->next = new Node(vec[i]);
        holder = holder->next;
    }
}
    
Polynomial::Polynomial() {
    head = new Node();
    head->next = new Node(0);
    degree = 0;
}
    
Polynomial::~Polynomial() {
    listClear(head);
}
    
Polynomial::Polynomial(const Polynomial& rhs) {
    degree = rhs.degree;
    head = new Node();
    head->next = new Node(rhs.head->next->data);
    Node* holder = head->next;
    Node* rhsHolder = rhs.head->next;
    size_t size = listLength(rhs.head->next);
    for (size_t i = size; i != 1; --i) {
        holder->next = new Node(rhsHolder->next->data);
        holder = holder->next;
        rhsHolder = rhsHolder->next;
    }
}
    
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    if (this != &rhs) {
        listClear(head);
        degree = rhs.degree;
        head = new Node();
        head->next = new Node(rhs.head->next->data);
        Node* holder = head->next;
        Node* rhsHolder = rhs.head->next;
        size_t size = listLength(rhs.head->next);
        for (size_t i = size; i != 1; --i) {
            holder->next = new Node(rhsHolder->next->data);
            holder = holder->next;
            rhsHolder = rhsHolder->next;
        }
    }
    return *this;
}
    
int Polynomial::evaluate(int n) {
    int result = head->next->data;
    Node* holder = head->next->next;
    int answer = 1;
    int currExp = 1;
    while (currExp != (degree+1)) {
        for (int each = 1; each != (currExp+1); each++){
            answer *= n;
        }
        answer *= holder->data;
        result += answer;
        answer = 1;
        holder = holder->next;
        ++currExp;
    }
    
    return result;
}
    
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
    size_t thisSize = listLength(head->next);
    size_t rhsSize = listLength(rhs.head->next);
    
    Node* tHold = head->next;
    Node* rHold = rhs.head->next;
    
    if (thisSize > rhsSize || thisSize == rhsSize) {
        for (size_t i = 0; i < rhsSize; i++) {
            tHold->data = tHold->data + rHold->data;
            tHold = tHold->next;
            rHold = rHold->next;
        }
    } else {
        for (size_t i = 1; i < thisSize; i++) {
            tHold->data = tHold->data + rHold->data;
            tHold = tHold->next;
            rHold = rHold->next;
        }
        
        tHold->data = tHold->data + rHold->data;
        rHold = rHold->next;
        
        size_t difference = rhsSize - thisSize;
        for (size_t j = 0; j < difference; j++) {
            tHold->next = new Node(rHold->data);
            rHold = rHold->next;
            tHold = tHold->next;
            ++degree;
        }
        
    }
    
    Node* check = head;
    while (check->next->next != nullptr) {
        check = check->next;
    }
    if (check->data == 0){
        listRemoveAfter(check->next);
        --degree;
    }
    
    return *this;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
    return !(lhs == rhs);
}
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial newPoly = lhs;
    return newPoly += rhs;
}
