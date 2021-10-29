#include "../include/graph.h"


Graph::Graph() {}

Graph::Graph(InfoAutomaton infoAut) {
  acceptStatesNames = infoAut.acceptanceStates;
  for (unsigned int i = 0; i < infoAut.statesSet.size(); i++) {
    if (find( acceptStatesNames.begin(), acceptStatesNames.end(),
    infoAut.statesSet[i]) != acceptStatesNames.end())
      states.push_back(State(infoAut.statesSet[i], true));
    else states.push_back(State (infoAut.statesSet[i]));
  }
  
  initialState = infoAut.initialState;
  alphabetBelt = infoAut.conveyorAlph;
  alphabetStack = infoAut.stackAlph;
  graphStack.push(infoAut.initialStack);

  for (auto trans: infoAut.transitions) 
    for (unsigned int i = 0; i < states.size(); i++) 
      if (states[i].getName() == trans[0]) {
        states[i].addTransition(Transition (trans[1], trans[2], vector<string> (trans.begin() + 4, trans.end()), trans[3]));
        break;
      }

  for (auto state: states) 
    if (infoAut.initialState == state.getName())
      initialState = state;
  currentState = initialState;
}

Graph::Graph(vector<State> S, vector<string> ASN, vector<string> AB, vector<string> AS, stack<string> GS, Belt CB) {
  states = S;
  acceptStatesNames = ASN;
  alphabetBelt = AB;
  alphabetStack = AS;
  graphStack = GS;
  conveyorBelt = CB;
}

vector<State> Graph::getStates() {
  return states;
}
vector<string> Graph::getAcceptStatesNames() {
  return acceptStatesNames;
}
vector<string> Graph::getAlphabetBelt() {
  return alphabetBelt;
}
vector<string> Graph::getAlphabetStack() {
  return alphabetStack;
}
stack<string> Graph::getGraphStack() {
  return graphStack;
}
State Graph::getInitialState() {
  return initialState;
}
Belt Graph::getConveyorBelt() {
  return conveyorBelt;
}
void Graph::setConveyorBelt(Belt cb) {
  conveyorBelt = cb;
}

State Graph::getStateByID(string id) {
  for(auto state: states)
    if (state.getName() == id)
      return state;
  exit(1);
}

bool Graph::checkInAlphabet(string charToCheck, vector<string> alphabet) {
  if (charToCheck == ".") return true;
  for (auto str: alphabet) if (str == charToCheck) return true;
  cout << "String not member of alphabet!" << endl;
  return false;
}

void Graph::doTransition(Transition tr, Belt& currentBelt, stack<string>& currentStack) {
  currentStack.pop();
  if (tr.getCharBelt() != ".") currentBelt.nextChar();
  if (tr.getInsertCharsStack()[0] != ".")
    for (int i = tr.getInsertCharsStack().size()-1; i >= 0; i--)
      currentStack.push(tr.getInsertCharsStack()[i]);
}

bool Graph::algorithm(Belt currentBelt, stack<string> currentStack, State newCS, bool writeMode) {
  if (!checkInAlphabet(currentBelt.getCurrent(), alphabetBelt)) return false;
  if (!checkInAlphabet(currentStack.top(), alphabetStack)) return false;

  vector<Transition> posTrans(newCS.possibleTransitions(currentBelt.getCurrent(), currentStack.top()));
  for (auto tr: posTrans) {
    Belt auxBelt = currentBelt;
    stack<string> auxStack = currentStack;
    doTransition(tr, auxBelt, auxStack);

    if (writeMode) writeTransition(tr, currentBelt, currentStack, newCS);
    if (algorithm(auxBelt, auxStack, getStateByID(tr.getIdStateTo()), writeMode))
      return true;
  }
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
  if (currentStack.empty() || currentBelt.getPointer() >= currentBelt.getBelt().size()) {
    return newCS.isAcceptance() ? true : false;
  }
#pragma GCC diagnostic pop
  return false;
}

void Graph::writeTransition(Transition tr, Belt currentBelt, stack<string> currentStack, State newCS) {
  cout << "-----------------------\nDescripción instantánea:" << endl;
  cout << "Cinta: " << currentBelt.getRemainer() << endl;
  cout << "Pila: " << stackToString(currentStack) << endl;
  cout << "Estado actual: " << newCS.getName() << endl;
  cout << "Transición a realizar: " << tr;
}

string Graph::stackToString(stack<string> stack) {
  string output;
  while (!stack.empty()) {
    output += stack.top();
    stack.pop();
  }
  return output;
}