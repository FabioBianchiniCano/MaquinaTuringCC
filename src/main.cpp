#include <iostream>

#include <stack> 
#include <vector>
#include <string>
#include <set>
#include <sstream>

#include "../include/readfile.h"
#include "../include/belt.h"
#include "../include/state.h"
#include "../include/transition.h"
#include "../include/machine.h"

using namespace std;

ostream& operator<<(ostream& os, const vector<string>& vec) {
  for(auto elem : vec)
    os << elem << " ";
  return os;
}

void usage() {
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << "\tUsage" << endl;
  cout << "\t./turing writeMode nameFile" << endl;
  cout << "\tBoth are mandatory arguments" << endl;
  cout << "\twriteMode -> 1: enabled, 2: disabled" << endl;
  cout << "\tIs not necesary to put the extension in the file name passed" << endl;
  cout << "--------------------------------------------------------------------------------" << endl;
}


int main(int argc, char *argv[]) {

  InfoMachine obj = readFile("Ejemplo_MT");
  cout << "obj.states " << obj.states << endl;
  cout << "obj.inputAlph " << obj.inputAlph << endl;
  cout << "obj.outputAlph " << obj.outputAlph << endl;
  cout << "obj.initialState " << obj.initialState << endl;
  cout << "obj.blankChar " << obj.blankChar << endl;
  cout << "obj.acceptanceStates " << obj.acceptanceStates << endl;
  for (auto tr: obj.transitions) cout << tr << endl;

  cout << "Bye!" << endl; 
}

