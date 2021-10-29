#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct InfoMachine {
  vector<string> states;
  vector<string> inputAlph;
  vector<string> outputAlph;
  string initialState;
  char blankChar;
  vector<string> acceptanceStates;
  vector<vector <string> > transitions;
};