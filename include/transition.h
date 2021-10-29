#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Transition {
  private:
    string charBelt;
    string charStack;
    vector<string> insertCharsStack;
    string idStateTo;
    string idStateFrom;

  public:
    Transition();
    Transition(string, string, vector<string>, string);
    void setStateFrom(string stateFrom) {idStateFrom = stateFrom; }
    string getIdStateFrom() { return idStateFrom; } 
    string getCharBelt(); 
    string getCharStack();
    vector<string> getInsertCharsStack();
    string getIdStateTo();
    void operator=(Transition);
    friend ostream& operator<<(ostream&, const Transition&);

};