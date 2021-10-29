#include "../include/state.h"

State::State() {}

State::State(string newName) {
  name = newName;
} 

State::State(string newName, vector<Transition> trans) {
  name = newName;
  transitions = trans;
}

State::State(string newName, bool condition) {
  name = newName;
  acceptance = condition;
} 

State::State(string newName, bool condition, vector<Transition> trans) {
  name = newName;
  acceptance = condition;
  transitions = trans;
} 

void State::operator=(State newState) {
  name = newState.getName();
  acceptance = newState.isAcceptance();
  for (auto tr: newState.getTransitions())
    transitions.push_back(tr);
}

string State::getName() {
  return name;
}
bool State::isAcceptance() {
  return acceptance;
}
vector<Transition> State::getTransitions() {
  return transitions;
}

void State::addTransition(Transition newTrans) {
  transitions.push_back(newTrans);
}

void State::toggleAcceptance() {
  acceptance = !acceptance;
}

vector<Transition> State::possibleTransitions(string charBelt, string charStack) {
  vector<Transition> finalTrans;
  for (auto tr: transitions) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
    if ((charBelt == tr.getCharBelt() && charStack == tr.getCharStack()) ||
    tr.getCharBelt() == "." && charStack == tr.getCharStack()) 
      finalTrans.push_back(tr);
#pragma GCC diagnostic pop
  }
  return finalTrans;
}