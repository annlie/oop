//
//  Annlie Nguyen
//  rec01
//
//  Program to run Conway's game of life


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream initialWorld("life.txt");
    if (!initialWorld) {
        cerr << "Could not open file" << endl;
        exit(1);
    }
    
    string line;
    
    cout << "Initial World" << endl;
    /*    while (getline(initialWorld, line)) { //print out initial world from file
     cout << line << endl;
     }
     
     cout << line << endl;
     */
    
    initialWorld.clear();
    initialWorld.seekg(0);
    
    const int ROWS = 8; //8 lines
    const int COLS = 20; //20 items per line
    vector<vector<char> > newWorld;
    
    //adds to newWorld
    for (int r = 0; r < ROWS; ++r) {
        newWorld.push_back(vector<char>(COLS));
        getline(initialWorld, line);
        for (int c = 0; c < COLS; ++c) {
            newWorld[r][c] = line[c];
        }
        
    }
    
    //prints out newWorld
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            cout << newWorld[r][c];
        }
        cout << endl;
    }
    
    
    vector<vector<char> > fixedWorld;
    
    for (int numRun = 1; numRun < 11; ++numRun) {
        cout << endl << endl;
        cout << "Generation: " << numRun << endl;
        for (int r = 0; r < ROWS; ++r) {
            fixedWorld.push_back(vector<char>(COLS));
            for (int c = 0; c < COLS; ++c) {
                int count = 0;
                char currChar = newWorld[r][c];
                
                //check each neighbor
                if (r-1 >= 0 && c-1 >= 0 && newWorld[r-1][c-1] == '*') {
                    count = count+ 1;
                }
                
                if (r-1 >= 0 && newWorld[r-1][c] == '*') {
                    count = count + 1;
                }
                
                if (r-1 >= 0 && c+1 < COLS && newWorld[r-1][c+1] == '*') {
                    count = count + 1;
                }
                
                if (c-1 >= 0 && newWorld[r][c-1] == '*') {
                    count = count + 1;
                }
                
                if (c+1 < COLS && newWorld[r][c+1] == '*') {
                    count = count + 1;
                }
                
                if (r+1 < ROWS && c-1 >= 0 && newWorld[r+1][c-1] == '*') {
                    count = count + 1;
                }
                
                if (r+1 < ROWS && newWorld[r+1][c] == '*') {
                    count = count + 1;
                }
                
                if (r+1 < ROWS && c+1 < COLS && newWorld[r+1][c+1] == '*') {
                    count = count + 1;
                }
                
                //cout << "count: " << count << endl;
                
                if (currChar == '*' && count == 2){
                    fixedWorld[r][c] = '*';
                } else if (currChar == '*' && count == 3){
                    fixedWorld[r][c] = '*';
                } else if (currChar == '*' && count < 2) {
                    fixedWorld[r][c] = '-';
                } else if (currChar == '*' && count > 3) {
                    fixedWorld[r][c] = '-';
                } else if (currChar == '-' && count == 3) {
                    fixedWorld[r][c] = '*';
                } else {
                    fixedWorld[r][c] = '-';
                }
            }
        }
        
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                cout << fixedWorld[r][c];
            }
            cout << endl;
        }
        newWorld = fixedWorld;
        
    }
    
    return 0;
}

