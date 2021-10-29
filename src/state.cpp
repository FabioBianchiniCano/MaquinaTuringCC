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

vector<Transition> State::possibleTransitions(string inputChar) {
  vector<Transition> finalTrans;
  for (auto tr: transitions) 
    if (tr.getInputChar() == inputChar) 
      finalTrans.push_back(tr);
  return finalTrans;
}