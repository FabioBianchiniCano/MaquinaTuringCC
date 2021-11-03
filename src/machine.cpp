#include "../include/machine.h"


Machine::Machine() {}

Machine::Machine(InfoMachine infoAut) {
  acceptanceStates = infoAut.acceptanceStates;
  // Busco en el vector de estados de aceptación todos los estados que me voy 
  // encontrando, si coinciden es que es un estado de aceptación y hay que 
  // insertarlo como tal, si no, como uno normal.
  for (unsigned int i = 0; i < infoAut.states.size(); i++) {
    if (find( acceptanceStates.begin(), acceptanceStates.end(),
    infoAut.states[i]) != acceptanceStates.end())
      states.push_back(State(infoAut.states[i], true));
    else states.push_back(State (infoAut.states[i]));
  }
  
  initialState = infoAut.initialState;
  alphabetInput = infoAut.inputAlph;
  alphabetOutput = infoAut.outputAlph;

  for (auto trans: infoAut.transitions) {
    for (unsigned int i = 0; i < states.size(); i++)  {
      if (states[i].getName() == trans[0]/*idStateFrom*/) {
        //                                   input    output    stateTo  stateFrom   direction                                    
        states[i].addTransition(Transition (trans[1], trans[3], trans[2], trans[0], trans[4]));
        break;
      }
    }
  }

  blank = infoAut.blankChar;

  // Inicializar estado inicial (y el actual, que son el mismo al principio)
  for (auto state: states) 
    if (infoAut.initialState == state.getName())
      initialState = state;
  currentState = initialState;
}

vector<State> Machine::getStates() {
  return states;
}
vector<string> Machine::getAcceptStatesNames() {
  return acceptanceStates;
}
vector<string> Machine::getAlphabetInput() {
  return alphabetInput;
}
vector<string> Machine::getAlphabetOutput() {
  return alphabetOutput;
}

State Machine::getInitialState() const {
  return initialState;
}
Belt Machine::getBelt() const {
  return belt;
}
void Machine::setBelt(Belt cb) {
  belt = cb;
}

State Machine::getStateByID(string id) {
  for(auto state: states)
    if (state.getName() == id)
      return state;
  cout << "Unexpected Error. State " << id << " not found. Exiting..." << endl;
  exit(1);
}

bool Machine::checkInAlphabet(string charToCheck, vector<string> alphabet) {
  if (charToCheck[0] == blank) return true;
  for (auto str: alphabet) if (str == charToCheck) return true;
  cout << "String \"" << charToCheck <<  "\" not member of alphabet!" << endl;
  return false;
}

ostream& operator<<(ostream& os, const Machine& mac) {
  os << "Current State: " << mac.getCurrent().getName() << endl;
  os << "Belt: " << endl << mac.getBelt() << endl;
  return os;
}

void Machine::doTransition(Transition tr, Belt& currentBelt) {
  currentBelt.writeChar(tr.getOutputChar()[0]); // toChar
  currentBelt.nextCharByDir(tr.getDirection());
}

bool Machine::algorithm(Belt currentBelt, State newCS, bool writeMode) {
  if (!checkInAlphabet(currentBelt.getCurrent(), alphabetInput)) return false;

  vector<Transition> posTrans(newCS.possibleTransitions(currentBelt.getCurrent()));
  for (auto tr: posTrans) {
    Belt auxBelt = currentBelt;
    doTransition(tr, auxBelt);

    if (!checkInAlphabet(tr.getOutputChar(), alphabetOutput)) return false;
    if (writeMode) writeTransition(tr, currentBelt, newCS);
    if (algorithm(auxBelt, getStateByID(tr.getIdStateTo()), writeMode))
      return true;
  }
  
  if (newCS.possibleTransitions(currentBelt.getCurrent()).empty()) {
    return newCS.isAcceptance() ? true : false;
  }
  return false;
}

void Machine::writeTransition(Transition tr, Belt currentBelt, State newCS) {
  // cout << "-----------------------\nDescripción instantánea:" << endl;
  cout << "Current State: " << newCS.getName() << endl;
  cout << "Belt: " << endl << currentBelt;
  cout << "Transición a realizar: " << tr;
  cout << "--------------------------------------------------\n";
}

