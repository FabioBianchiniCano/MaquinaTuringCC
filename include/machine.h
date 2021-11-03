#pragma once
#include <algorithm>
#include <stack> 
#include "state.h"
#include "belt.h"
#include "infoautomaton.h"

using namespace std;

class Machine {
  private:
    vector<State> states;
    vector<string> acceptanceStates;
    vector<string> alphabetInput;
    vector<string> alphabetOutput;
    char blank;
    Belt belt;
    State initialState;
    State currentState;
    

  public:
    Machine();
    Machine(InfoMachine);
    vector<State> getStates();
    vector<string> getAcceptStatesNames();
    vector<string> getAlphabetInput();
    vector<string> getAlphabetOutput();
    State getInitialState() const;
    Belt getBelt() const;
    void setBelt(Belt);
    State getCurrent() const {return currentState;}
    State getStateByID(string);
    bool checkInAlphabet(string, vector<string>);
    void doTransition(Transition, Belt&);
    bool algorithm(Belt, State, bool);
    void writeTransition(Transition, Belt, State);
    string stackToString(stack<string> stack);

    friend ostream& operator<<(ostream&, const Machine&);
};