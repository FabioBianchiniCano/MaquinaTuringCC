#include "../include/belt.h"
#include <typeinfo>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"
char *UPARROW = u8"\uFFEA";
#pragma GCC diagnostic pop


Belt::Belt() {
  belt.push_back(blank);
  belt.push_back(blank);
}

Belt::Belt(string newString, char newBlank) {
  blank = newBlank;
  belt.push_back(blank);
  for (auto c: newString)
    belt.push_back(c);
  belt.push_back(blank);
}

Belt::Belt(string newString) {
  belt.push_back(blank);
  for (auto c: newString)
    belt.push_back(c);
  belt.push_back(blank);
}

string Belt::getBelt() {
  return belt;
}

int Belt::getPointer() {
  return pointer;
}

string Belt::getCurrent() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
  return (pointer >= belt.size()) ? "." : string{belt[pointer]};
#pragma GCC diagnostic pop
}
string Belt::getRemainer() {
  return belt.substr(pointer, belt.size() - pointer);
}

string Belt::rightChar() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
  if (pointer >= belt.size()-1) enlargeRight();
#pragma GCC diagnostic pop
  return belt.substr(pointer++, 1);
}

string Belt::leftChar() {
  if (pointer <= 0) enlargeLeft();
  return belt.substr(pointer--, 1);
}

string Belt::nextCharByDir(string dir) {
  return (dir == "R") ? rightChar() : leftChar(); 
}

void Belt::enlargeLeft() {
  belt.insert(0, 1, blank);
  pointer++;
}

void Belt::enlargeRight() {
  belt += blank;
}

void Belt::writeChar(char outputChar) {
  belt[pointer] = outputChar;
}

void Belt::operator= (Belt newBelt) {
  belt = newBelt.getBelt();
  pointer = newBelt.getPointer();
}

ostream& operator<<(ostream& os, const Belt& bl) {
  os << bl.belt << endl;
  for (int i = 0; i < bl.pointer; i++)
    os << " ";
  os << UPARROW << endl;
  return os;
}
