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
    char blanck;
    State initialState;
    Belt belt;
    State currentState;
    

  public:
    Machine();
    Machine(InfoMachine);
    vector<State> getStates();
    vector<string> getAcceptStatesNames();
    vector<string> getAlphabetInput();
    vector<string> getAlphabetOutput();
    State getInitialState();
    Belt getBelt();
    void setBelt(Belt);
    State getStateByID(string);
    bool checkInAlphabet(string, vector<string>);
    void doTransition(Transition, Belt&, stack<string>&);
    bool algorithm(Belt, stack<string>, State, bool);
    void writeTransition(Transition, Belt , stack<string> , State );
    string stackToString(stack<string> stack);
};