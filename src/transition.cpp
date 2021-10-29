#include "../include/transition.h"

Transition::Transition() {}

Transition::Transition(string CB, string CS, vector<string> ICS, string IST) {
  charBelt = CB;
  charStack = CS;
  insertCharsStack = ICS;
  idStateTo = IST;
}

  string Transition::getCharBelt() {
    return charBelt;
  } 
  string Transition::getCharStack() {
    return charStack;
  }
  vector<string> Transition::getInsertCharsStack() {
    return insertCharsStack;
  }
  string Transition::getIdStateTo() {
    return idStateTo;
  }


void Transition::operator=(Transition newTrans) {
  charBelt = newTrans.getCharBelt();
  charStack = newTrans.getCharStack();
  insertCharsStack = newTrans.getInsertCharsStack();
  idStateTo = newTrans.getIdStateTo();
}

ostream& operator<<(ostream& os, const Transition& tr) {
  os << tr.charBelt << " " << tr.charStack << " " << tr.idStateTo << " ";
  for (auto CS: tr.insertCharsStack) os << CS << " ";
  os << endl;
  return os;
}
