#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "infoautomaton.h"

using namespace std;

vector<string> splitString(string str, string separator = " ") {
  vector<string> finalStr;
  int start = 0;
  int end = str.find(separator);
  while (end != -1) {
    finalStr.push_back(str.substr(start, end - start));
    start = end + separator.size();
    end = str.find(separator, start);
  }
  finalStr.push_back(str.substr(start, end - start));
  return finalStr;
}

InfoAutomaton readFile(string filename) {
  InfoAutomaton infoFile;
  string line;
  ifstream file("../lib/" + filename + ".txt");
  if (file.fail()) {
    cout << "File not found." << endl;
    exit(1);
  }
  int i = 0;

  while (getline (file, line)) {
    line = line.substr(0, line.find_first_of('#'));
    if (!line.empty()) {
      switch (i) {
      case 0:
        infoFile.statesSet = splitString(line);
        break;
      case 1:
        infoFile.conveyorAlph = splitString(line);
        break;
      case 2:
        infoFile.stackAlph = splitString(line);
        break;
      case 3:
        infoFile.initialState = line;
        break;
      case 4:
        infoFile.initialStack = line;
        break;
      case 5:
        infoFile.acceptanceStates = splitString(line);
        break;
      default:
        infoFile.transitions.push_back(splitString(line));
        break;
      }
      i++;
    }
  }
  file.close();

  return infoFile;
}