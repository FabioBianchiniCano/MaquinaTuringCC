#pragma once
#include "transition.h"

using namespace std;

class State {
  private:
    string name;
    bool acceptance = false;
    vector<Transition> transitions;

  public:
    State();
    State(string);
    State(string, vector<Transition>);
    State(string, bool);
    State(string, bool, vector<Transition>);

    void operator=(State);
    string getName();
    bool isAcceptance();
    vector<Transition> getTransitions();
    void addTransition(Transition);
    void toggleAcceptance();
    vector<Transition> possibleTransitions(string, string);

};