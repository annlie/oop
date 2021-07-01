//
//  Annlie Nguyen
//  rec12
//
//  Doubly linked lists with iterators

#include <iostream>
using namespace std;


class List {
    friend ostream& operator<<(ostream& os, const List& rhs) {
        Node* first = rhs.header->next;
        while (first->next != nullptr) {
            os << first->data << ' ';
            first = first->next;
        }
        return os;
    }
private:
    struct Node {
        Node(Node* prev = nullptr, int data = NULL, Node* after = nullptr) : next(after), before(prev), data(data) {}
        Node* next;
        Node* before;
        int data;
    };
    
    size_t sizeOfList = 0;
    Node* header;
    Node* trailer;
    
public:
    class iterator {
        friend class List;
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
            return lhs.one == rhs.one;
        }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
            return !(lhs == rhs);
        }
    private:
        Node* one;
    public:
        iterator(Node* node) : one(node) {}
        
        iterator& operator++() {
            one = one->next;
            return *this;
        }
        iterator& operator--() {
            one = one->before;
            return *this;
        }
        
        int& operator*() {
            return one->data;
        }
    };
    
    iterator begin() { return iterator(header->next); }
    iterator end() { return nullptr; }
    
    List() {
        header = new Node();
        trailer = new Node(header);
        header->next = trailer;
    }
    
    void push_back(int data) {
        Node* newNode = new Node(trailer->before, data, trailer);
        trailer->before->next = newNode;
        trailer->before = newNode;
        ++sizeOfList;
    }
    
    void pop_back() {
        Node* prev = trailer->before->before;
        prev->next = trailer;
        Node* curr = trailer->before;
        trailer->before = prev;
        delete curr;
        --sizeOfList;
    }
    
    int front() const { return header->next->data; }
    int& front() { return header->next->data; }
    
    int back() const { return trailer->before->data; }
    int& back() { return trailer->before->data; }
    size_t size() { return sizeOfList; }
    
    void push_front(int data) {
        Node* after = header->next;
        Node* newNode = new Node(header, data, after);
        after->before = newNode;
        header->next = newNode;
        ++sizeOfList;
    }
    void pop_front() {
        Node* after = header->next->next;
        Node* curr = header->next;
        after->before = header;
        header->next = after;
        delete curr;
        --sizeOfList;
    }
    
    void clear() {
        size_t original = sizeOfList;
        for (size_t i = 0; i < original; i++) {
            pop_back();
        }
    }
    
    int& operator[](size_t index) {
        Node* curr = header->next;
        for (size_t i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data;
    }
    
    //insert before iterator
    iterator insert(iterator iter, int data) {
        Node* curr = nullptr;
        Node* prev = nullptr;
        if (iter == nullptr) {
            curr = trailer;
            prev = trailer->before;
        } else {
            curr = iter.one;
            prev = curr->before;
        }
        Node* newNode = new Node(prev, data, curr);
        prev->next = newNode;
        curr->before = newNode;
        ++sizeOfList;
        return iterator(newNode);
        //return iterator to new item
    }
    
    //delete curr node that iterator holding
    iterator erase(iterator iter) {
        --sizeOfList;
        Node* curr = nullptr;
        Node* prev = nullptr;
        Node* after = nullptr;
        if (iter == nullptr) {
            curr = trailer->before;
            prev = trailer->before->before;
            after = trailer;
        } else {
            curr = iter.one;
            prev = curr->before;
            after = curr->next;
        }
        iterator result = iterator(after);
        delete curr;
        prev->next = after;
        after->before = prev;
        return result;
        //return iterator to node after one being deleted
    }
    
};

void printListInfo(List& myList) {
    cout << "size: " << myList.size()
    << ", front: " << myList.front()
    << ", back(): " << myList.back()
    << ", list: " << myList << endl;
}

int main() {
    
    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";
    
    // Task2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";
    
    // Task3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";
    
    // Task4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    
    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";
    
    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
    << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    myList.clear();
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    List::iterator iter = myList.begin();
    ++iter;
    ++iter;
    myList.insert(iter, 11);
    printListInfo(myList);
    cout << "===================\n";
    
    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list wixth insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    myList.clear();
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    iter = myList.begin();
    ++iter;
    ++iter;
    myList.erase(iter);
    printListInfo(myList);
    cout << "===================\n";
    
}
