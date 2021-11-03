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

  Machine machine1(readFile(argv[1]));

  bool writeMode;
  istringstream(argv[2]) >> writeMode;

  string belt;

  bool otherString = false;
  do {
    cout << "Write the belt you want to test: ";
    cin >> belt;
    machine1.setBelt(belt);
    cout << endl << "--------------------------------------------------\n";
    machine1.algorithm(machine1.getBelt(), machine1.getInitialState(), writeMode) ? 
      cout << "String accepted!" << endl :
      cout << "String not accepted..." << endl;

    cout << "\nDo you want to test another string? (1:yes / 0:no): ";
    cin >> otherString;
  } while (otherString);

  cout << "\nBye!" << endl; 
}

