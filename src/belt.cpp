#include "../include/belt.h"
#include <typeinfo>

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
  return (pointer == belt.size()) ? "." : string{belt[pointer]};
#pragma GCC diagnostic pop
}
string Belt::getRemainer() {
  return belt.substr(pointer, belt.size() - pointer);
}


string Belt::nextChar() {
  return belt.substr(pointer++, 1);
}

void Belt::operator= (Belt newBelt) {
  belt = newBelt.getBelt();
  pointer = newBelt.getPointer();
}