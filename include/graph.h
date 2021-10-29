#pragma once
#include <algorithm>
#include <stack> 
#include "state.h"
#include "belt.h"
#include "infoautomaton.h"

using namespace std;

class Graph {
  private:
    vector<State> states;
    vector<string> acceptStatesNames;
    vector<string> alphabetBelt;
    vector<string> alphabetStack;
    stack<string> graphStack;
    State initialState;
    Belt conveyorBelt;
    State currentState;
    

  public:
    Graph();
    Graph(vector<State>, vector<string>, vector<string>, vector<string>, stack<string>, Belt);
    Graph(InfoAutomaton);
    vector<State> getStates();
    vector<string> getAcceptStatesNames();
    vector<string> getAlphabetBelt();
    vector<string> getAlphabetStack();
    State getInitialState();
    stack<string> getGraphStack();
    Belt getConveyorBelt();
    void setConveyorBelt(Belt);
    State getStateByID(string);
    bool checkInAlphabet(string, vector<string>);
    void doTransition(Transition, Belt&, stack<string>&);
    bool algorithm(Belt, stack<string>, State, bool);
    void writeTransition(Transition, Belt , stack<string> , State );
    string stackToString(stack<string> stack);
};