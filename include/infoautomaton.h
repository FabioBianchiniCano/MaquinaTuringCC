#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for(auto elem : vec) os << elem ;
  return os;
}

struct InfoMachine {
  vector<string> states;
  vector<string> inputAlph;
  vector<string> outputAlph;
  string initialState;
  char blankChar;
  vector<string> acceptanceStates;
  vector<vector <string> > transitions;
};