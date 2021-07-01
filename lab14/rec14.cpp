//
//  main.cpp
//  rec14
//
//  Created by Annlie Nguyen on 12/14/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    Node(int x = 0, Node* l = nullptr) : data(x), next(l) {}
    int data;
    Node* next;
};

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

bool onesBool(int n) {
    
    if (n == 0) { return true; }
    if (n == 1) { return false; }
    
    if (n%2 == 0) { return onesBool(n/2); }
    else { return !onesBool(n/2); }
}


//task 1
int ones(int n) {
    if (n == 0) { return 0; }
    if (n == 1) { return 1; }
    if (n%2 == 0) { return ones(n/2); }
    else { return ones(n/2) + 1; }
}

bool checkOnes(int n) {
    if (n < 0) { cout << "negative number, "; return false; }
    int res = ones(n);
    if (res%2 == 0) { return true; }
    else { return false; }
}

//task 2
Node* newList(Node* list1, Node* list2) {
    if (list1 == nullptr && list2 == nullptr) { return nullptr; }
    if (list1 == nullptr || list2 == nullptr) {
        Node* newNode = new Node();
        if (list1 == nullptr) {
            newNode->data = list2->data;
            newNode->next = newList(list2->next, nullptr);
        } else if (list2 == nullptr) {
            newNode->data = list1->data;
            newNode->next = newList(list1->next, nullptr);
        }
        return newNode;
    }
    Node* newNode = new Node();
    newNode->data = list1->data + list2->data;
    newNode->next = newList(list1->next, list2->next);
    return newNode;
}

//task 3
//int max(TNode* root) {
//    //if (root == nullptr) { return -1; }
//    if (root == nullptr) {
//        throw invalid_argument("node is null");
//    }
//
//    int largest = root->data;
//
//    int left = max(root->left);
//    int right = max(root->right);
//
//    if (largest > left && largest > right) { return largest; }
//    else if (right > left) { return right; }
//    else { return left; }
//}
int max(TNode* root) {
    if (root == nullptr) {
        throw invalid_argument("node is null");
    }
    
    int largest = root->data;
    
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }
    
    int left = root->data;
    int right = root->data;
    if (root->left != nullptr) {
        left = max(root->left);
    }
    if (root->right != nullptr) {
        right = max(root->right);
    }
    return std::max(largest,std::max(left,right));
    //    if (largest > right && largest > left) { return largest; }
    //    else if (left > right) { return left; }
    //    else { return right; }
    
}

//task 4
bool palindrome(char* some, int length) {
    if (length == 0) { return true; }
    if (length == 1) { return true; }
    //    if (length == 2) {
    //        return *some == some[length-1];
    //    }
    
    bool isPalin = palindrome(&some[1], length-2);
    if (isPalin) {
        char opp = some[length-1];
        if (*some == opp) { return true; }
        return false;
    }
    
    return false;
}

//task 5
int hanoi(int n, char start, char target, char spare) {
    int count = 0;
    if (n > 0) {
        count = 1 + hanoi(n-1, start, spare, target);
        count += hanoi(n-1, spare, target, start);
    }
    return count;
}


int main() {
    //task 1
    cout << "task 1: " << endl;
    cout << "checking 20 in binary: " << checkOnes(20) << endl; //true
    cout << "checking 25 in binary: " << checkOnes(25) << endl; //false
    cout << "checking 11 in binary: " << checkOnes(11) << endl; //false
    cout << "checking 4 in binary: " << checkOnes(4) << endl; //false
    cout << "checking 6 in binary: " << checkOnes(6) << endl; //true
    cout << "checking 100 in binary: " << checkOnes(100) << endl; //false
    cout << "checking -6 in binary: " << checkOnes(-6) << endl; //true
    
    //task 2
    cout << endl << endl << "task 2: " << endl;
    Node* newNode = new Node(1);
    newNode->next = new Node(2);
    newNode->next->next = new Node(3);
    
    Node* newerNode = new Node(1);
    newerNode->next = new Node(2);
    newerNode->next->next = new Node(3);
    
    Node* neww = newList(newNode, newerNode);
    Node* temp = neww;
    for (size_t i = 0; i < 3; i++) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    
    
    //task 3
    cout << endl << endl << "task 3: " << endl;
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    try {
        cout << "find max for tree: " << max(&f) << endl;
    }
    catch (invalid_argument er) {
        cerr << "invalid argument: " << er.what() << endl;
    }
    
    
    //task 4
    cout << endl << endl << "task 4: " << endl;
    char s[] = "racecar";
    char t[] = "a";
    char y[] = "aa";
    char q[] = "ab";
    char p[] = "noon";
    char w[] = "annlie";
    
    cout << "checking palindrome racecar: " << palindrome(s,7) << endl;  //true
    cout << "checking palindrome a: " << palindrome(t,1) << endl; //true
    cout << "checking palindrome aa: " << palindrome(y,2) << endl; //true
    cout << "checking palindrome ab: " << palindrome(q,2) << endl; //false
    cout << "checking palindrome noon: " << palindrome(p,4) << endl; //true
    cout << "checking palindrome annlie: " << palindrome(w,6) << endl; //false
    
    
    //task 5
    cout << endl << endl << "task 5: " << endl;
    cout << "hanoi(1, 'a', 'b', 'c'): " << hanoi(1, 'a', 'b', 'c') << endl;
    cout << "hanoi(2, 'a', 'b', 'c'): " << hanoi(2, 'a', 'b', 'c') << endl;
    cout << "hanoi(3, 'a', 'b', 'c'): " << hanoi(3, 'a', 'b', 'c') << endl;
    cout << "hanoi(4, 'a', 'b', 'c'): " << hanoi(4, 'a', 'b', 'c') << endl;
    cout << "hanoi(5, 'a', 'b', 'c'): " << hanoi(5, 'a', 'b', 'c') << endl;
    cout << "hanoi(6, 'a', 'b', 'c'): " << hanoi(6, 'a', 'b', 'c') << endl;
    cout << "hanoi(7, 'a', 'b', 'c'): " << hanoi(7, 'a', 'b', 'c') << endl;
    cout << "hanoi(8, 'a', 'b', 'c'): " << hanoi(8, 'a', 'b', 'c') << endl;
    cout << "hanoi(9, 'a', 'b', 'c'): " << hanoi(9, 'a', 'b', 'c') << endl;
    cout << "hanoi(10, 'a', 'b', 'c'): " << hanoi(10, 'a', 'b', 'c') << endl;
}

//void mystery(int n) {
//    if (n>1) {
//        cout << 'a';
//        mystery(n/2);
//        cout << 'b';
//        mystery(n/2);
//    }
//    cout << 'c';
//}

/*
 task 6
 
 if 0: c
 if 1: c
 if 2: acbcc
 if 3: acbcc
 if 4: a acbcc b acbcc c
 if 5: aacbccbacbccc
 if 6: aacbccbacbccc
 if 7: aacbccbacbccc
 if 8: a (a acbcc b acbcc c ) b aacbccbacbccc  c
 if 9: aaacbccbacbcccbaacbccbacbcccc
 if 10: aaacbccbacbcccbaacbccbacbcccc
 
 */
