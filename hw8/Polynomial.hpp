//
//  Polynomial.hpp
//  hw08
//
//  Created by Annlie Nguyen on 12/8/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Node;

class Polynomial {
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
    
    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
    
public:
    Polynomial(std::vector<int> vec);
    
    Polynomial();
    
    ~Polynomial();
    
    Polynomial(const Polynomial& rhs);
    
    Polynomial& operator=(const Polynomial& rhs);
    
    int evaluate(int n);
    
    Polynomial& operator+=(const Polynomial& rhs);
private:
    double degree = 0;
    Node* head = nullptr; //head node that holds nothing
};

bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

#endif /* Polynomial_hpp */
