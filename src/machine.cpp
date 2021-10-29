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

  for (auto trans: infoAut.transitions) 
    for (unsigned int i = 0; i < states.size(); i++) 
      if (states[i].getName() == trans[0]) {
        //                                   input    output    stateTo  stateFrom   direction                                    
        states[i].addTransition(Transition (trans[1], trans[3], trans[2], trans[0], trans[4]));
        break;
      }

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

State Machine::getInitialState() {
  return initialState;
}
Belt Machine::getBelt() {
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
  if (charToCheck == ".") return true;
  for (auto str: alphabet) if (str == charToCheck) return true;
  cout << "String not member of alphabet!" << endl;
  return false;
}

// void Machine::doTransition(Transition tr, Belt& currentBelt, stack<string>& currentStack) {
//   currentStack.pop();
//   if (tr.getCharBelt() != ".") currentBelt.nextChar();
//   if (tr.getInsertCharsStack()[0] != ".")
//     for (int i = tr.getInsertCharsStack().size()-1; i >= 0; i--)
//       currentStack.push(tr.getInsertCharsStack()[i]);
// }

// bool Machine::algorithm(Belt currentBelt, stack<string> currentStack, State newCS, bool writeMode) {
//   if (!checkInAlphabet(currentBelt.getCurrent(), alphabetInput)) return false;
//   if (!checkInAlphabet(currentStack.top(), alphabetOutput)) return false;

//   vector<Transition> posTrans(newCS.possibleTransitions(currentBelt.getCurrent(), currentStack.top()));
//   for (auto tr: posTrans) {
//     Belt auxBelt = currentBelt;
//     stack<string> auxStack = currentStack;
//     doTransition(tr, auxBelt, auxStack);

//     if (writeMode) writeTransition(tr, currentBelt, currentStack, newCS);
//     if (algorithm(auxBelt, auxStack, getStateByID(tr.getIdStateTo()), writeMode))
//       return true;
//   }
//   #pragma GCC diagnostic push
//   #pragma GCC diagnostic ignored "-Wsign-compare"
//   if (currentStack.empty() || currentBelt.getPointer() >= currentBelt.getBelt().size()) {
//     return newCS.isAcceptance() ? true : false;
//   }
//   #pragma GCC diagnostic pop
//   return false;
// }

// void Machine::writeTransition(Transition tr, Belt currentBelt, stack<string> currentStack, State newCS) {
//   cout << "-----------------------\nDescripción instantánea:" << endl;
//   cout << "Cinta: " << currentBelt.getRemainer() << endl;
//   cout << "Pila: " << stackToString(currentStack) << endl;
//   cout << "Estado actual: " << newCS.getName() << endl;
//   cout << "Transición a realizar: " << tr;
// }

