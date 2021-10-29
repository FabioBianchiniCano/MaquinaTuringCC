#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct InfoAutomaton {
  vector<string> statesSet;
  vector<string> conveyorAlph;
  vector<string> stackAlph;
  string initialState;
  string initialStack;
  vector<string> acceptanceStates;
  vector<vector <string> > transitions;
};