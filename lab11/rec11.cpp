//
//  Annlie Nguyen
//  rec11
//
//  Linked lists
//

#include <iostream>
#include <vector>
using namespace std;

// Node to be used a part of linked list
struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// listInsertHead: adds a data item to the beginning of a [possibly empty] list
void listInsertHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like.
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listInsertHead(result, vals[index-1]);
    }
    return result;
}

//--------------------------------------------------------

void splice(Node* adding, Node*& original) {
    cout << "Splicing!" << endl;
    Node* afterOriginal = original->next;
    original->next = adding;
    while(adding != nullptr) {
        adding = adding->next;
        if(adding->next == nullptr) {
            break;
        }
    }
    adding->next = afterOriginal;
}

//Node* isSublist(Node* want, Node* original) {
//    Node* beginning = nullptr;
//    while (original != nullptr) {
//        if (original->data == want->data) {
//            beginning = original;
//            want = want->next;
//            original = original->next;
//            break;
//        }
//        original = original->next;
//    }
//    while (want != nullptr && original != nullptr) {
//        if (want->data != original->data) {
//            return nullptr;
//        }
//        want = want->next;
//        original = original->next;
//    }
//    if (beginning!= nullptr && want == nullptr) {
//        return beginning;
//    }
//    return nullptr;
//}
Node* isSublist(Node* want, Node* original) {
    Node* holder = original;
    int count = 0;
    int size = 0;
    bool found = false;
    while (original != nullptr) {
        ++count;
        while(want != nullptr) {
            Node* nextPtr = original;
            if(original->data == want->data) {
                size += 1;
                found = true;
                want = want->next;
                nextPtr = nextPtr->next;
            } else {
                found = false;
                break;
            }
        } //end second loop
        if(want == nullptr && found) {
            //            cout << "Count:" << count << endl;
            //            cout << "Size:" << size << endl;
            int run = count - size;
            while (run != 0) {
                holder = holder->next;
                --run;
            }
            return holder;
        }
        original = original->next;
    } //end first loop
    return nullptr;
}

int main() {
    //    Node* l1 = listBuild({5,7,9,1});
    //    Node* l2 = listBuild({6,3,2});
    //
    //    Node* head = l1->next;
    //    Node* headHolder1 = l1;
    //    Node* headHolder2 = l2;
    //
    //    cout << "L1: ";
    //    while(headHolder1 != nullptr) {
    //        cout << headHolder1->data << ' ';
    //        headHolder1 = headHolder1->next;
    //    }
    //    cout << endl;
    //    cout << "L2: ";
    //    while(headHolder2 != nullptr) {
    //        cout << headHolder2->data << ' ';
    //        headHolder2 = headHolder2->next;
    //    }
    //    cout << endl;
    //
    //    splice(l2, head);
    //
    //    headHolder1 = l1;
    //    headHolder2 = l2;
    //
    //    cout << "L1: ";
    //    while(headHolder1 != nullptr) {
    //        cout << headHolder1->data << ' ';
    //        headHolder1 = headHolder1->next;
    //    }
    //    cout << endl;
    //
    //    cout << "L2: ";
    //    while(headHolder2 != nullptr) {
    //        cout << headHolder2->data << ' ';
    //        headHolder2 = headHolder2->next;
    //    }
    //    cout << endl;
    //
    //    listClear(l1);
    //    cout << "cleared one" << endl;
    //    listClear(l2);
    //    cout << "cleared two" << endl;
    
    
    Node* l3 = listBuild({1,2,3,2,3,2,4,5,6});
    Node* l4 = listBuild({2,3,2});
    
    Node* headHolder3 = l3;
    Node* headHolder4 = l4;
    
    cout << "Target: ";
    while(headHolder3 != nullptr) {
        cout << headHolder3->data << ' ';
        headHolder3 = headHolder3->next;
    }
    cout << endl;
    
    cout << "Attempt match: ";
    while(headHolder4 != nullptr) {
        cout << headHolder4->data << ' ';
        headHolder4 = headHolder4->next;
    }
    cout << endl;
    
    Node* check = isSublist(l4, l3);
    if (check == nullptr) {
        cout << "Failed to match" << endl;
    } else {
        Node* headHolderF = check;
        while(headHolderF != nullptr) {
            cout << headHolderF->data << ' ';
            headHolderF = headHolderF->next;
        }
        cout << endl;
    }
    
    return 0;
}
