//
//  Annlie Nguyen
//  hw01
//
// Program for a medieval times game where warriors battle

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct Warrior {
    string name;
    int strength;
};

void createWarrior(vector<Warrior>& warVec, const string& name, const int& strength);
void battleWarriors(vector<Warrior>& warVec, const string& first, const string& second);
void displayStatus(const vector<Warrior>& warVec);

int main() {
    vector<Warrior> warriorCollection;
    
    ifstream warriorFile("warriors.txt");
    if (!warriorFile) {
        cerr << "File not opened" << endl;
        exit(1);
    }
    
    string commandCheck;
    string name;
    int initialStrength;
    string firstWarrior;
    string secondWarrior;
    
    while (warriorFile >> commandCheck) {
        if (commandCheck == "Warrior") {
            warriorFile >> name;
            warriorFile >> initialStrength;
            createWarrior(warriorCollection, name, initialStrength);
        } else if (commandCheck == "Status") {
            displayStatus(warriorCollection);
        } else { //commandCheck == "Battle"
            warriorFile >> firstWarrior;
            warriorFile >> secondWarrior;
            battleWarriors(warriorCollection, firstWarrior, secondWarrior);
        }
    }
    
    return 0;
}


void createWarrior(vector<Warrior>& warVec, const string& name, const int& strength) {
    Warrior newWarrior;
    newWarrior.name = name;
    newWarrior.strength = strength;
    warVec.push_back(newWarrior);
}


void battleWarriors(vector<Warrior>& warVec, const string& first, const string& second) {
    cout << first << " battles " << second << endl;
    size_t firstPos = -1;
    size_t secondPos = -1;
    
    for (size_t i = 0; i < warVec.size(); i++) {
        if (warVec[i].name == first) { //finds index of "first" warrior
            firstPos = i;
        }
        if (warVec[i].name == second) { //finds index of "second" warrior
            secondPos = i;
        }
        if (firstPos != -1 && secondPos != -1) { //ends loop once both are found
            break;
        }
    }
    
    if (warVec[firstPos].strength == 0 && warVec[secondPos].strength > 0) {
        cout << "He's dead, " << second << endl;
    } else if (warVec[firstPos].strength > 0 && warVec[secondPos].strength == 0) {
        cout << "He's dead, " << first << endl;
    } else if (warVec[firstPos].strength == warVec[secondPos].strength
               && warVec[firstPos].strength == 0) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
        //only need to check if one strength equal to 0 since both equal anyways
    } else if (warVec[firstPos].strength == warVec[secondPos].strength) {
        warVec[firstPos].strength = 0;
        warVec[secondPos].strength = 0;
        cout << "Mutual Annihilation: " << first << " and " << second;
        cout << " die at each other's hands" << endl;
    } else if (warVec[firstPos].strength > warVec[secondPos].strength) {
        warVec[firstPos].strength -= warVec[secondPos].strength;
        warVec[secondPos].strength = 0;
        cout << first << " defeats " << second << endl;
    } else if (warVec[firstPos].strength < warVec[secondPos].strength) {
        warVec[secondPos].strength -= warVec[firstPos].strength;
        warVec[firstPos].strength = 0;
        cout << second << " defeats " << first << endl;
    }
    
}


void displayStatus(const vector<Warrior>& warVec) {
    cout << "There are: " << warVec.size() << " warriors" << endl;
    for (size_t i = 0; i < warVec.size(); i++) {
        cout << "Warrior: " << warVec[i].name << ", ";
        cout << "strength: " << warVec[i].strength << endl;
    }
}
