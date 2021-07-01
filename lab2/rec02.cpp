//  Annlie Nguyen
//  rec02
//  Program to load hydrocarbons from file
//  Create a collection of hydrocarbons and sort by formula

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Hydrocarbon {
    vector<string> names;
    int carbon;
    int hydrogen;
};

void openStream(ifstream& ifs);
void createVector(ifstream& ifs, vector<Hydrocarbon>& hVec);
void sortVector(vector<Hydrocarbon>& hVec);
void printVector(const vector<Hydrocarbon>& hVec);

int main() {
    ifstream hydroFile;
    vector<Hydrocarbon> hydroCollection;
    
    openStream(hydroFile);
    createVector(hydroFile, hydroCollection);
    sortVector(hydroCollection);
    printVector(hydroCollection);
    
    return 0;
}

void openStream(ifstream& ifs) {
    string file;
    cout << "Please enter a file name." << endl;
    cin >> file;
    ifs.open(file);
    while (!ifs) {
        cerr << "Invalid file name. Enter a different one." << endl;
        ifs.clear();
        cin >> file;
        ifs.open(file);
    }
}

void createVector(ifstream& ifs, vector<Hydrocarbon>& hVec) {
    string name;
    int carbon;
    int hydrogen;
    char c;
    char h;
    size_t pos = -1;
    
    while (ifs >> name >> c >> carbon >> h >> hydrogen) {
        Hydrocarbon any;
        
        for (size_t i = 0; i < hVec.size(); ++i) {
            if (hVec[i].carbon == carbon && hVec[i].hydrogen == hydrogen) {
                pos = i;
            }
        }
        
        if (pos == -1) {
            any.names.push_back(name);
            any.carbon = carbon;
            any.hydrogen = hydrogen;
            hVec.push_back(any);
        } else {
            hVec[pos].names.push_back(name);
            pos = -1;
        }
        
    }
    
}

void sortVector(vector<Hydrocarbon>& hVec) {
    Hydrocarbon curr;
    Hydrocarbon swap;
    
    for (size_t i = 0; i < hVec.size(); i++) {
        for (size_t j = 0; j < (hVec.size()-1); j++) {
            if (hVec[j].carbon > hVec[j+1].carbon) {
                curr = hVec[j];
                swap = hVec[j+1];
                hVec[j] = swap;
                hVec[j+1] = curr;
            } else if (hVec[j].carbon == hVec[j+1].carbon) {
                if (hVec[j].hydrogen > hVec[j+1].hydrogen) {
                    curr = hVec[j];
                    swap = hVec[j+1];
                    hVec[j] = swap;
                    hVec[j+1] = curr;
                }
            }
        }
    }
}

/*
 BEFORE SORT RESULTS
 C4H10 n-Butane Butane iso-Butane
 C3H3 Propyne
 C4H2 1,3-Butadiyne
 C6H14 Hexane
 C5H12 Pentane
 */

void printVector(const vector<Hydrocarbon>& hVec) {
    for (size_t i = 0; i < hVec.size(); ++i) {
        cout << "C" << hVec[i].carbon << "H" << hVec[i].hydrogen << ' ' ;
        for (size_t j = 0; j < hVec[i].names.size(); ++j) {
            cout << hVec[i].names[j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
