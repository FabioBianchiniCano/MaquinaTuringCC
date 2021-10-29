#include <iostream>

#include <stack> 
#include <vector>
#include <string>
#include <set>
#include <sstream>

#include "../include/readfile.h"
#include "../include/belt.h"
// #include "../include/state.h"
// #include "../include/transition.h"
// #include "../include/graph.h"

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
  Belt newBelt;
  cout << newBelt.getBelt() << endl;
  cout << "Bye!" << endl; 
}

