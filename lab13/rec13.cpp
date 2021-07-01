//
//  Annlie Nguyen
//  rec13
//
//  STL

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

//task 9
void listPrint(const list<int>& lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << ' ';
    }
}

//task 10
void listRanged(const list<int>& lst) {
    for (int each : lst) { cout << each << ' '; }
}

//task 11
void autoList(const list<int>& lst) {
    for (auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << ' ';
        it++;
    }
}

//task 12
list<int>::const_iterator listFind(const list<int>& lst, int search) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        if (*it == search) {
            return it;
        }
    }
    return lst.end();
}

//task 13
auto autoFind(const list<int>& lst, int search) {
    for (auto it = lst.begin(); it != lst.end(); it++) {
        if (*it == search) { return it; }
    }
    return lst.end();
}

//task 15
bool isEven(int n) { return n%2 == 0; }

//task 16
class myEven {
public:
    bool operator() (int n) { return n%2 == 0; }
};

//task 19
list<int>::const_iterator ourFind(list<int>::const_iterator start, list<int>::const_iterator end, int target) {
    cout << "in our find!!!" << endl;
    for (list<int>::const_iterator it = start; it != end; it++) {
        if (*it == target) { return it; }
    }
    return end;
}

//task 20
template <class T, class U>
T ourFind(T start, T end, U target) {
    cout << "in template find!!!" << endl;
    for (T it = start; it != end; it++) {
        if (*it == target) { return it; }
    }
    return end;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vec{8,2,9,4,7,6};
    for (int each : vec) { cout << each << ' '; }
    
    cout << "\n=======\n";
    
    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> lst(vec.begin(), vec.end());
    for (int each : lst) { cout << each << ' '; }
    
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vec.begin(), vec.end());
    for (int each : vec) { cout << each << ' '; }
    cout << endl;
    for (int each : lst) { cout << each << ' '; }
    
    cout << "\n=======\n";
    
    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    //0 2 4 6
    for (size_t i = 0; i < vec.size(); i++) {
        if (i%2 == 0) { cout << vec[i] << ' '; }
    }
    
    cout << "\n=======\n";
    
    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    //    for (size_t i = 0; i < list.size(); i++) {
    //        if (i%2 == 0) { cout << list[i] << ' '; }
    //    }
    
    cout << "\n=======\n";
    
    //
    // Iterators
    //
    
    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2) {
        cout << *it << ' ';
    }
    
    cout << "\n=======\n";
    
    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << ' ';
        it++;
    }
    
    cout << "\n=======\n";
    
    // 8. Sorting a list
    cout << "Task 8:\n";
    lst.sort();
    for (int each : lst) { cout << each << ' '; }
    
    cout << "\n=======\n";
    
    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    listPrint(lst);
    cout << endl;
    
    cout << "=======\n";
    
    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    listRanged(lst);
    cout << endl;
    
    cout << "=======\n";
    
    //
    // Auto
    //
    
    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    autoList(lst);
    cout << endl;
    
    cout << "=======\n";
    
    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int> newlst{1,2,3,4,5,6};
    list<int>::const_iterator toPrint = listFind(newlst, 2);
    if (toPrint == newlst.end()) { cout << "not found" << endl; }
    else { cout << "found!" << endl; }
    
    cout << "=======\n";
    
    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    toPrint = autoFind(newlst, 8);
    if (toPrint == newlst.end()) { cout << "not found" << endl; }
    else { cout << "found!" << endl; }
    
    cout << "=======\n";
    
    //
    // Generic Algorithms
    //
    
    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    toPrint = find(newlst.begin(), newlst.end(), 13);
    if (toPrint == newlst.end()) { cout << "not found" << endl; }
    else { cout << "found!" << endl; }
    
    cout << "=======\n";
    
    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    //newlst = 1,2,3,4,5,6
    list<int> noEven{1,3,5,7,9,7,5,7,11};
    list<int>::iterator it = find_if(noEven.begin(), noEven.end(), isEven);
    if (it == noEven.end()) { cout << "no even found" << endl; }
    else { cout << "even found: " << *it << endl; }
    
    cout << "=======\n";
    
    // 16. Functor
    cout << "Task 16:\n";
    it = find_if(noEven.begin(), noEven.end(), myEven());
    if (it == noEven.end()) { cout << "no even found" << endl; }
    else { cout << "even found: " << *it << endl; }
    
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    //    [] (int a, int b) { cout << a+b << endl; } (4,5);
    //
    //    int result = [] (int a, int b) { return a+b; } (4,5);
    //    cout << "result: " << result << endl;
    //
    //    int result2 = [] (int a, int b) -> int { return a+b; } (4,5);
    //    cout << "result2: " << result2 << endl;
    
    it = find_if(noEven.begin(), noEven.end(), [] (int n) { return n%2 == 0; });
    if (it == noEven.end()) { cout << "no even found" << endl; }
    else { cout << "even found: " << *it << endl; }
    
    cout << "=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[lst.size()];
    copy(lst.begin(), lst.end(), arr);
    for (int each : arr) { cout << each << ' '; }
    cout << endl;
    
    cout << "=======\n";
    
    //
    // Templated Functions
    //
    
    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::const_iterator newPrint = ourFind(lst.begin(), lst.end(), 13);
    if (newPrint == lst.end()) { cout << "not found" << endl; }
    else { cout << "found!" << endl; }
    
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    auto print = ourFind(vec.begin(), vec.end(), 2);
    if (print == vec.end()) { cout << "not found" << endl; }
    else { cout << "found!" << endl; }
    
    cout << "=======\n";
    
    //
    // Associative collections
    //
    
    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string> complete;
    ifstream file("pooh-nopunc.txt");
    if (!file) { cerr << "not open!!!" << endl; exit(1); }
    string check;
    while (file >> check) {
        if (complete.size() == 0) { complete.push_back(check); }
        bool found = false;
        for (size_t i = 0; i < complete.size(); i++) {
            if (check == complete[i]) {
                found = true;
                break;
            }
        }
        if (!found) { complete.push_back(check); }
    }
    file.close();
    for (const string& each : complete) { cout << each << ' '; }
    cout << endl;
    cout << "size: " << complete.size() << endl;
    
    cout << "\n=======\n";
    
    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    ifstream file2("pooh-nopunc.txt");
    if (!file2) { cerr << "not open!!!" << endl; exit(1); }
    set<string> mySet;
    while (file2 >> check) {
        mySet.insert(check);
    }
    for (const string& each : mySet) { cout << each << ' '; }
    cout << endl << "size: " << mySet.size() << endl;
    file2.close();
    
    cout << "=======\n";
    
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    ifstream file3("pooh-nopunc.txt");
    if (!file3) { cerr << "not open!!!" << endl; exit(1); }
    int count = 1;
    while (file3 >> check) {
        wordMap[check].push_back(count);
        count++;
    }
    
    for (auto each : mySet) {
        cout << each << ' ';
        for (size_t i = 0; i < wordMap[each].size(); i++) {
            cout << wordMap[each][i] << ' ';
        }
        cout << endl;
    }
    
    cout << "=======\n";
}
