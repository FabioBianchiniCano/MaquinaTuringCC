#include "../include/transition.h"

Transition::Transition() {}

Transition::Transition(string IC, string OC, string ST, string SF, string D) {
  inputChar = IC;
  outputChar = OC;
  idStateTo = ST;
  idStateFrom = SF;
  direction = D;
}


string Transition::getInputChar() {
  return inputChar;
}
string Transition::getOutputChar() {
  return outputChar;
}
string Transition::getIdStateTo() {
  return idStateTo;
}
string Transition::getIdStateFrom() {
  return idStateFrom;
} 
string Transition::getDirection() {
  return direction;
}
void Transition::setInputChar(string input) {
  inputChar = input;
}
void Transition::setOutputChar(string output) {
  outputChar = output;
}
void Transition::setIdStateTo(string stateTo) {
  idStateTo = stateTo;
}
void Transition::setStateFrom(string stateFrom) {
  idStateFrom = stateFrom;
}
void Transition::setDirection(string dir) {
  direction = dir;
}
void Transition::operator=(Transition newTrans) {
  inputChar = newTrans.getInputChar();
  outputChar = newTrans.getOutputChar();
  idStateTo = newTrans.getIdStateTo();
  idStateFrom = newTrans.getIdStateFrom();
  direction = newTrans.getDirection();
}

ostream& operator<<(ostream& os, const Transition& tr) {
  os << tr.idStateFrom << " " << tr.inputChar << " " 
     << tr.idStateTo   << " " << tr.outputChar << " "
     << tr.direction << " ";
  os << endl;
  return os;
}
